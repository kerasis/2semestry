//1.+	Базовый конструктор
//2.+	Конструктор копирования(правило 3 - х)
//3.+	Оператор присваивания копированием(правило 3 - х)
//4.+	Деструктор(правило 3 - х)
//5.+	Операторы + и +=
//6.+	Оператор[] – чтение и изменение элемента
//7.+	Операторы <, >, ==
//8.+	Операторы ввода и вывода в поток                                                    ? про объявление массива(его длина)
//9.+	Метод find – поиск первого вхождения символа в строку слева
//10.+	 Метод length – длина строки
//11.+	 Метод c_str – получить массив char
//12.+	 Метод at для получения доступа(чтение и изменение) к элементу строки с проверкой на выход за пределы строки
#include <stdlib.h>
#include <iostream>
struct String
{
private:
    size_t m_size;
    char* m_str = nullptr;
public:
    String() = default;
    String(int c, size_t size) = delete;//запрет неявного преобразования char в int

    //1.базовый конструктор
    String(char a, size_t size) : m_size(size+1), m_str(new char[m_size])
    {
        std::fill(m_str, m_str + m_size-1, a);
        m_str[m_size-1] = '\0';
    }

    //1.конструктор строкой
    String(const char* str_from) : m_size(strlen(str_from) + 1), m_str(new char[m_size])
    {
        std::copy(str_from, str_from + m_size, m_str);
       //m_str[m_size-1] = '\0';
    }

    //2. конструктор копирования c делигирующим конструктором
    String(const String& other) : String(other.m_str)//m_size(other.m_size), m_str(new char[m_size])
    {
        //std::copy(other.m_str, other.m_str + m_size, m_str);
    }

    //3.оператор присваивания копированием
    String& operator=(String temporary)
    {
        std::swap(m_size, temporary.m_size);
        std::swap(m_str, temporary.m_str);
        return *this;
    }

    //5
    String& operator+=(const String& other)
    {
        //String temp(*this);
        //(*this).m_size += other.m_size;
        ////delete[](*this).m_str;
        //(*this).m_str = new char[(*this).m_size];
        //std::copy(temp.m_str, temp.m_str + temp.m_size, m_str);
        //std::copy(other.m_str, other.m_str + other.m_size+1, (*this).m_str + temp.m_size-1);
        //(*this).m_str[(*this).m_size-1] = '\0';
        //return *this;
        char* cur_mas = nullptr;
        cur_mas = new char[(*this).m_size+ other.m_size-1];
        std::copy((*this).m_str, (*this).m_str + (*this).m_size - 1, cur_mas);
               
        for (int i = ((*this).m_size-1); i < ((*this).m_size + other.m_size - 1); i++)
        {
            cur_mas[i] = other.m_str[i - (*this).m_size+1];
        }
       
        delete[](*this).m_str;
        (*this).m_size += other.m_size-1;
        (*this).m_str = cur_mas;
        return *this;
    }
    String operator+(const String& other)
    {
        String temp = *this;
        temp += other;
        return temp;
    }

    //4.
    ~String()
    {
        if (m_str != nullptr)
        {
            delete[] m_str;
        }
    }

    //6
    char& operator[](int ind)
    {
        return m_str[ind];
    }

    //9
    int find(const char c)
    {
        for (int i = 0; i < (m_size - 1); i++)
        {
            if (m_str[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    //10
    int length()
    {
        return (m_size - 1);
    }

    //11
    const char* c_str()
    {
        return m_str;
    }

    //12
    char& at(int ind)
    {
        char* pt = nullptr;
        if (0 <= ind && ind <= (m_size - 1))
        {
            return m_str[ind];
        }
        throw "incorrect ind";
        
    }

    //7
    bool operator==(const String& other) const
    {
        if ((*this).m_size != other.m_size)
        {
            return false;
        }
        
        for (int i = 0; i < (*this).m_size-1; i++)
        {
            if ((*this).m_str[i] != other.m_str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator<(const String& other) const
    {
        if (*this == other) { return false; }
        int ind_stop = (std::max((*this).m_size, other.m_size) - 1);
        for (int i = 0; i < ind_stop; i++)
        {
            if ((*this).m_str[i] > other.m_str[i]) { return false; }
        }
        if ((*this).m_size > other.m_size) { return false; }
        else { return true; }
    }

    bool operator>(const String& other) const
    {
        if (*this == other) { return false; }
        else if (*this < other) { return false; }
        else { return true; }
    }

    
    friend std::istream& operator>>(std::istream& in, String& str);
    friend std::ostream& operator<<(std::ostream& out, const String& str);

    void Print()
    {
        for (int i = 0; i < m_size; i++)
        {
            std::cout << m_str[i];
        }
    }
};



//8
std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.m_str;
    return out;
}

std::istream& operator>>(std::istream& in, String& str)
{
    std::cout << "enter length: ";   
    in >> str.m_size;
    str.m_size += 1;
    str.m_str = new char[str.m_size];
    std::cout << '\n' << "enter line: ";
    for (int i = 0; i < (str.m_size - 1); i++)
    {
        in >> str.m_str[i];
    }
    str.m_str[str.m_size - 1] = '\0';

    return in;
}


int main()
{
    String s1('q',3);
    String s2("d abobus");
    String s3(s2);
    s1.Print();
    std::cout << "\n";
    s2.Print();
    std::cout << "\n";
    s3.Print();
    std::cout << "\n";

    s1 += s2;
    s1.Print();
    std::cout << "\n";
    String s4 = s2 + s2 + s1;
    s4.Print();
    std::cout << "\n";
    std::cout << s1.find('c') << ' ' << s1.find('q') << ' ' << s2.find('u') << std::endl;
    std::cout << "length str: " << s1.length() << std::endl;

    std::cout << s2.c_str() << ' ' << (s2.c_str() + 2) << std::endl;
      
    std::cout << s2[3] << std::endl;
    s2[3] = 'a';
    std::cout << s2[3] << std::endl;
    s2.Print();
    std::cout << "\n";
      
    try
    {
        std::cout << s2.at(600) << std::endl;
    }
    catch(const char* msg)
    {
        std::cout << msg << std::endl;
    }

    String s_1("aaa");
    String s_1_1("aaa");
    String s_2("abcd");
    String s_3("adbce");
    String s_4("bcda");

    std::cout << (s_1 == s_1_1) << " " << (s_2 < s_3) << " " << (s_3 > s_2) << " " << (s_2 < s_4) << std::endl;
   
    std::cout << s1 << std::endl;

    std::cout << "enter str: ";
    String s_in;
    std::cin >> s_in;
    std::cout << s_in;
}
