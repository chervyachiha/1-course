//Лабораторная работа №3
//«Комплексные числа»
#include <iostream>
class Complex {
private:
    double m_real_part;
    double m_imag_part;
public:
    Complex(double real_part = 0.0, double imag_part = 0.0) : m_real_part(real_part), m_imag_part(imag_part)
    {
        std::cout << "Basic constructor" << std::endl;
    }
    Complex(const Complex &z) {
        std::cout << "Copy constructor" << std::endl;
        m_real_part = z.m_real_part;
        m_imag_part = z.m_imag_part;
    }
    Complex &operator=(Complex z) {
        std::cout << "Copy assigment operator" << std::endl;
        std::swap(m_real_part, z.m_real_part);
        std::swap(m_imag_part, z.m_imag_part);
        return *this;
    }
    Complex &operator+=(const Complex &z)
    {
        (*this).m_real_part += z.m_real_part;
        (*this).m_imag_part += z.m_imag_part;
        return *this;
    }
    Complex &operator*=(const Complex &z)
    {
        double k=(*this).m_real_part;
        (*this).m_real_part = ((*this).m_real_part*z.m_real_part) -  ((*this).m_imag_part * z.m_imag_part);
        (*this).m_imag_part = (k*z.m_imag_part) + ((*this).m_imag_part * z.m_real_part);
        return *this;
    }
    //префиксный
    Complex& operator++ ()
    {
        this -> m_real_part+=1;
        return *this;
    }
    //постфиксный
    Complex operator++(int)
    {
        Complex temp = *this;
        this -> m_real_part +=1;
        return temp;
    }
    friend std::ostream& operator<< (std::ostream& out, const Complex& z);
    friend std::istream& operator>> (std::istream& in, Complex& z);
    ~Complex(){}
};
Complex operator+ (const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp += z2;
    return temp;
}
Complex operator* (const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp *= z2;
    return temp;
}
std::ostream& operator<< (std::ostream& out, const Complex& z)
{
    out << z.m_real_part << "+" << z.m_imag_part << "i";
    return out;
}
std::istream& operator>> (std::istream& in, Complex& z)
{
    in >> z.m_real_part >> z.m_imag_part;
    return in;
}
int main()
{
    Complex z1(10,4), z2(3,2);
    std::cout<<z1<<" " << z2<<std::endl;
    std::cout<<"Умножение комплексных чисел "<<z1*z2<<std::endl;
    std::cout<<"Сложение комплексных чисел "<<z1+z2<<std::endl;
    return 0;
}