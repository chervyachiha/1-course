#include <iostream>
#include <math.h>
class KinematicSolver
{
private:
    double m_alpha;
    double m_beta;
    double L1;
    double L2;
    double m_m[2] = { NULL };
public:
    void set()
    {
        std::cout<<"Длина между двигателями L1:"<< std::endl;
        std::cin >> L1;
        std::cout<<"Длина между двигателем и фломастером L2:"<< std::endl;
        std::cin >> L2;
        std::cout<<"Координаты пишущей части фломастера x and y:"<< std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cin >> m_m[i];
        }
    }
    int check()
    {
        if ((L1 == NULL) ||  (L2 == NULL))
        {
            std::cout << "Не введены длины" << std::endl;
            return 0;
        }
        if (m_m[0] == NULL || m_m[1] == NULL)
        {
            std::cout << "Не введены координаты точки М" << std::endl;
            return 0;
        }
        if (sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1])>L1+L2) {
            std::cout << "Точка слишком далеко" << std::endl;
            return 0;
        }
        return 1;
    }
    void Solve()
    {
        double p = sqrt(m_m[0] * m_m[0] + m_m[1] * m_m[1]);
        double gamma = acos((pow(L2,2)+pow(L1,2)-pow(p,2))/(2*L1*L2));
        m_beta = 180-(gamma*180)/3.141592653589793;
        double B = acos((pow(p,2)+pow(L1,2)-pow(L2,2))/(2*L1*p));
        double A = acos(m_m[0]/p);
        m_alpha=(B+A)*180/3.141592653589793;
        std::cout <<"alpha: "<< m_alpha << " beta: " << m_beta;
    }
};
int main()
{
    KinematicSolver M;
    M.set();
    if(M.check()==1)
        M.Solve();
    return 0;
}
//L1 - 3, L2 - 4, M(4,3)
//Ответ: 90,90