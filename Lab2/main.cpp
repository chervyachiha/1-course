//Лабораторная работа №2
//«Самодельный string»
//Реализуйте класс String для работы со строками. Понятное дело, что std::string для реализации использовать нельзя, только char.
//У вас должны быть реализованы:
//Базовый конструктор ++++
//Конструктор копирования (правило 3-х) +++
//Оператор присваивания копированием (правило 3-х)+++
//Деструктор (правило 3-х) +++
//Операторы + и +=  +++
//Оператор [] – чтение и изменение элемента +++
//Операторы <, >, == +++
//Операторы ввода и вывода в поток +++
//Метод find – поиск первого вхождения символа в строку слева+++
// Метод length – длина строки +++
// Метод c_str – получить массив char +++
// Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки

#include <iostream>
class String
{
private:
    size_t m_size = 1;
    char* m_str = nullptr;
    friend String operator+( String& s1, String& s2);
public:
    String()= default;
    //Преобразование из int в char
    String(char c, size_t size): m_size(size), m_str(new char [size+1])
    {
        std::memcpy(m_str, m_str + m_size, c);
        m_str[m_size]=0;
    }
    //Constructor Member initializer list
    String(char* str):m_size(strlen(str)), m_str(new char[m_size])
    {
        std::cout<<"Constructor Member initializer list"<< std::endl;
        std::copy(str, str+m_size, m_str);
        m_str[m_size]=0;
    }
    //Конструктор копирования
    String(const String& other):String(other.m_str)
    {
        std::cout<<"Copy constructor"<<std::endl;
    }
    String& operator=(String temp)
    {
        std::cout<<"Copy assigment operator"<<std::endl;
        std::swap(m_size, temp.m_size);
        std::swap(m_str, temp.m_str);
        return *this;
    }
    String& operator+=(String& other)
    {
        char* k = new char[m_size+other.m_size];
        std::copy(m_str,m_str+m_size, k);
        std::copy(other.m_str, other.m_str + other.m_size, k + m_size);
        delete [] m_str;
        std::copy(k, k+m_size+other.m_size, m_str);
        m_size += other.m_size;
        delete [] k;
        return *this;
    }
    //чтение и изменение элемента
    char& operator[](int index)
    {
        return m_str[index];
    }
   char& at(int index)
    {
        if (0<= index && index < m_size)
            return m_str[index];
        else
        {
            std::cout<<"Выход за предел"<<std::endl;
        }
    }
    //Операторы <, >, ==
    bool operator < (String& other ) const
    {
        return (strcmp(this->m_str, other.m_str) < 0);
        return m_size < other.m_size;
    }
    bool operator > (String& other) const
    {
        return (strcmp(this->m_str, other.m_str) > 0);
        return m_size > other.m_size;
    }
    bool operator == (String& other ) const
    {
        return (strcmp(this->m_str, other.m_str) == 0);
        return (m_size == other.m_size);
    }

    int length() const
    {
        return m_size;
    }
    //Метод find – поиск первого вхождения символа в строку слева
    int find (char v)
    {
        for (int i =0; i < m_size; i++)
        {
            if (m_str[i] == v)
                return i;
        }
        return -1;
    }
    char* c_str() const
    {
        return m_str;
    }
    friend std::istream& operator>> (std::istream& in, String& s);
    friend std::ostream& operator<< (std::ostream& out, const String& s);
~String()
{
    std::cout<<"Dectructor"<<std::endl;
    delete[] m_str;
}
};
String operator+( String& s1, String& s2)
{
    String a = s1;
    a += s2;
    return a;
}
std::istream& operator>> (std::istream& in, String& s)
{
    char d;
    while (in.get(d))
    {
        if (d=='\n' || d==' ')
        {
            break;
        }
        char* f = new char[s.m_size+1];
        std::copy(s.m_str,s.m_str+s.m_size, f);
        f[s.m_size]=d;
        delete [] s.m_str;
        std::copy(f, f+s.m_size+1, s.m_str);
        s.m_size += 1;
        delete [] f;
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, const String& s)
{
    for(int i =0; i<s.m_size; i++)
    {
        out<<s.m_str[i];
    }
    return out;
}
int main() {
    String g("Hello world");
    String g3("Good");
    String g4("Food");
    std::cout<<g3.c_str()<<std::endl;
    std::cout<<g3.length()<<std::endl;
    std::cout<<g4.at(2)<<std::endl;;
    std::cout<<(g>g4)<<std::endl;
    std::cin>> g;
    std::cout<<g<<std::endl;
    std::cout<<g4.find('o')<<std::endl;
    return 0;
}