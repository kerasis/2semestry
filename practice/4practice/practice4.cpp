//В системе «Умный дом» используется управляющий компьютер, который взаимодействует с различными приборами.
//Приборы подразделяются на несколько категорий :

//1.	Счетчики электрической энергии
        //a.Меркурий 230
        //b.Нева МТ314
        //c.Энергомера CE308

//2.	Блоки ввода дискретных сигналов :
        //a.Reallab NL - 16HV
        //b.Приборэлектро PRE - 16
        //c.Энергосервис ЭНМВ - 1 - 24
        
//3.	Блоки управления отоплением
        //a.Ouman S203
        //b.Овен ТРМ232

//Получить данные от каждого прибора можно через метод
//
//void poll() {
//	std::cout << “Device name” << std::endl;
//	// Некоторая реализация получения данных, которую вам делать
//	// не нужно.
//}
#include <iostream>

class appliances
{
public:
    virtual void poll() = 0;
     
};


class energy_meter : public appliances
{
public:
    void poll() override
    {
        std::cout << "energymeter" << std::endl;
    }
};



class mercury : public energy_meter
{
private:
    std::string m_name = "Меркурий 230";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

class neva : public energy_meter
{
private:
    std::string m_name = "Нева МТ314";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

class energomera : public energy_meter
{
private:
    std::string m_name = "Энергомера CE308";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};



class signal_output :public appliances
{
public:
    void poll() override
    {
        std::cout << "signal output" << std::endl;
    }
};

class reallab : public signal_output
{
private:
    std::string m_name = "Reallab NL - 16HV";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

class pre : public signal_output
{
private:
    std::string m_name = "Приборэлектро PRE - 16";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

class energoserv : public signal_output
{
private:
    std::string m_name = "Энергосервис ЭНМВ - 1 - 24";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};



class heating_bloks : public appliances
{
public:
    void poll() override
    {
        std::cout << "heating bloks" << std::endl;
    }

};

class ouman: public heating_bloks
{
private:
    std::string m_name = "Ouman S203";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

class oven : public heating_bloks
{
private:
    std::string m_name = "Овен ТРМ232";
public:
    void poll() override
    {
        std::cout << m_name << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    ouman o;
    o.poll();

    pre pr;
    pr.poll();
}

 