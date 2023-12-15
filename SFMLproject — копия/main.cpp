#include <SFML/Graphics.hpp>
#include "map.h"
using namespace sf;

float offsetX=0, offsetY=0;

class Hero{
public:
float dx, dy;//скорость
sf::FloatRect rect;//координаты
bool onGround;//на земле ли находится персонаж
sf::Sprite sprite;//содержит картинку
float Move;//текущий кадр
    Hero(Texture &image)
    {
        sprite.setTexture(image);
        rect = FloatRect(100,180,16,16);

        dx=0.2;
        dy=0.2;
        Move = 0;
    }

    void Collision( int dir)
    {
        for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
            for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
            {
                if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'G') || (TileMap[i][j] == 'K') || (TileMap[i][j] == 'W')
                || (TileMap[i][j] == 'R') || (TileMap[i][j] == 'O') || (TileMap[i][j] == 'a')){
                    if (dx > 0 && dir == 0)
                        rect.left = j * 16 - rect.width;
                    if (dx < 0 && dir == 0)
                        rect.left = j * 16 + 16;
                    if (dy > 0 && dir == 1)
                    {
                        rect.top = i * 16 - rect.height;
                        dy = 0;
                        onGround = true;
                    }
                    if (dy < 0 && dir == 1) {
                        rect.top = i * 16 + 16;
                        dy = 0;
                    }
                }

                /*if (TileMap[i][j] == '0') {
                    TileMap[i][j] = ' ';
                }*/
            }
    }
    void update(float time){
        rect.left +=dx*time;
        Collision(0);

        if (!onGround)
            dy=dy+0.0005*time;
        rect.top +=dy*time;
        onGround = false;
        Collision(1);

        Move +=0.009*time;
        if (Move >6)
            Move  -= 6;
        if (dx>0)
            sprite.setTextureRect(sf::IntRect(16*int(Move), 0, 16, 16));
        if (dx<0)
            sprite.setTextureRect(sf::IntRect(16*int(Move)+16,0,-16,16));

        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
        dx=0;
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 250), "Game");//создаёт окно // VideoMode - размер окна

    sf::Image map_image;//объект изображения для карты
    map_image.loadFromFile("images/map.png");//загружаем файл для карты
    map_image.createMaskFromColor(Color::White);
    sf::Texture map;//текстура карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой
    sf::Sprite s_map;//создаём спрайт для карты
    s_map.setTexture(map);


    sf::Texture herotexture;
    herotexture.loadFromFile("images/girl/Walk_3.png");
    Hero p(herotexture);

    sf::Clock clock;

    while (window.isOpen())
    {
        float time= clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time=time/700;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)//нужно для закрытия окна
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p.dx = 0.01;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p.dx = -0.01;
        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         {
             if (p.onGround)
             {
                 p.dy = -0.3;
                 p.onGround=false;
             }
         }
         p.update(time);
         if (p.rect.left>200)
             offsetX = p.rect.left - 200;
         /*if (p.rect.top > (700/2))
             offsetY = p.rect.top - 700/2;*/
        window.clear(sf::Color(107,140,255));//очищает текущее окно
         for (int i=0; i < H; i++)
             for (int j = 0; j < W; j++)
             {
                 if (TileMap[i][j] == 'P')
                     s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
                 if (TileMap[i][j] == 'G')
                     s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
                 if (TileMap[i][j] == 'K')
                     s_map.setTextureRect(sf::IntRect(128, 0, 32, 32));
                 if (TileMap[i][j] == 'W')
                     s_map.setTextureRect(sf::IntRect(160, 0, 32, 32));
                 if (TileMap[i][j] == 'R')
                     s_map.setTextureRect(sf::IntRect(188, 0, 32, 32));
                 if (TileMap[i][j] == 'O')
                     s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
                 if (TileMap[i][j] == 'c')
                     s_map.setTextureRect(sf::IntRect(342, 0, 93, 50));
                 if (TileMap[i][j] == 'u')
                     s_map.setTextureRect(sf::IntRect(270, 0, 54, 45));
                 if (TileMap[i][j] == 'e')
                     s_map.setTextureRect(sf::IntRect(434, 11, 60, 20));
                 if (TileMap[i][j] == 'a')
                     continue;
                 if (TileMap[i][j] == ' ')
                     continue;
                 s_map.setPosition(j*16 - offsetX, i*16 - offsetY);
                 window.draw(s_map);

             }
         window.draw(p.sprite);//рисует
         window.display();//показывается в окне
     }
    return 0;
}







//Style::Fullscreen - запуск на полный экран (писать в RenderWindow) (лучше написать когда проект будет готов)