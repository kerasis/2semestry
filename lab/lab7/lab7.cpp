//Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами :
//1.	Треугольник
//2.	Прямоугольник
//3.	Круг
//
//Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.
//
//Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур.

#include <iostream>
#include <stdlib.h> 
class geometry
{
private:
    std::string color;
   
public:
    geometry(std::string string)
    {
        color = string;
    }

    virtual void square() = 0;

    std::string getColor()
    {
        return color;
    }

};

class traingle : public geometry
{
private:
    double coordinates[3][2] = {};
public:
    traingle(std::string string) : geometry(string)
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << "enter x and y: "; 
            std::cin >> coordinates[i][0] >> coordinates[i][1];
            std::cout << std::endl;
        }
    }

    void square() override
    {
        double m_square;
        m_square = 0.5 * ((coordinates[1][0] - coordinates[0][0]) * (coordinates[2][1] - coordinates[0][1]) - (coordinates[2][0] - coordinates[0][0]) * (coordinates[1][1] - coordinates[0][1]));
        m_square = abs(m_square);
        std::cout << "traingle square = " << m_square << std::endl;
    }
};

class circle : public geometry
{
private:
    double coordinates[2] = {};
    double radius;
public:
    circle(std::string string) : geometry(string)
    {
        std::cout << "enter x and y: ";
        std::cin >> coordinates[0] >> coordinates[1];
        std::cout << std::endl;
        std::cout << "enter radius: ";
        std::cin >> radius;
        std::cout << std::endl;
    }

    void square() override
    {
        double m_square = 3.14 * radius * radius;
        std::cout << "circle square = " << m_square << std::endl;
    }
};

class rectangle : public geometry
{
private:
    double coordinates[3][2] = {};
    
public:
    rectangle(std::string string) : geometry(string)
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << "enter x and y: ";
            std::cin >> coordinates[i][0] >> coordinates[i][1];
            std::cout << std::endl;
        }  
    }

    void square() override
    {
        double m_a = sqrt(pow((coordinates[0][0]-coordinates[1][0]),2) + pow((coordinates[0][1] - coordinates[1][1]), 2));
        double m_b = sqrt(pow((coordinates[1][0] - coordinates[2][0]), 2) + pow((coordinates[1][1] - coordinates[2][1]), 2));
        double m_square = m_a * m_b;
        std::cout << "rectangle square = " << m_square << std::endl;
    }
};


int main()
{
    traingle tr("red");
    rectangle rec("blue");
    tr.square();
    rec.square();
    std::cout << tr.getColor();
}

