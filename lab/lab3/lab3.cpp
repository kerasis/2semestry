//1.+	Базовый конструктор
//2.+	Конструктор копирования
//3.+	Оператор присваивания копированием
//4.+-	Деструктор
//5.+	Операторы += и + , *= и *
//6.+	Оператор ++ префиксный и постфиксный(увеличение действительной части числа на 1)
//7.+	Операторы ввода и вывода

#include <iostream>

class Complex
{
private :
    double m_a;
    double m_b;
public:
    Complex(char a, char b) = delete;
    Complex(char a) = delete;
    
    explicit Complex(double a = 0.0, double b = 0.0) : m_a(a), m_b(b) {}
    
    Complex(const Complex& z)
    {
        m_a = z.m_a;
        m_b = z.m_b;
    }
    ~Complex() = default;
    Complex& operator=(Complex z)
    {
        std::swap(m_a, z.m_a);
        std::swap(m_b, z.m_b);
        return *this;
    }

    Complex& operator+=(const Complex& z)
    {
        this->m_a += z.m_a;
        this->m_b += z.m_b;
        return *this;
    }
    Complex operator+(const Complex& z)
    {
        Complex temp = *this;
        temp += z;
        return temp;
    }
    Complex& operator*=(const Complex& z)
    {
        this->m_a *= z.m_a;
        this->m_b *= z.m_b;
        return *this;
    }
    Complex operator*(const Complex& z)
    {
        Complex temp = *this;
        temp *= z;
        return temp;
    }
    //преф
    Complex& operator++()
    {
        this->m_a += 1;
        return *this;
    }
    //пост
    Complex& operator++(int)
    {
        Complex temp = *this;
        this->m_a += 1;
        return temp;
    }


    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);
};

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    out << z.m_a << " " << z.m_b << "i";
    return out;
}
std::istream& operator>>(std::istream& in, Complex& z)
{
    in >> z.m_a >> z.m_b;
    return in;
}

int main()
{
    Complex z1;
    Complex z2(1,2);

    std::cin >> z1;
    std::cout << (z1 + z2) << std::endl;

    z1++;
    std::cout << z1 << std::endl;

    //Complex z3('a');
    


}

