//Вашей задачей будет создать шаблонный класс для реализации стека.В нем нужно предусмотреть методы :
//1.+	Конструктор с указанием размера стека
//2.+	Метод size
//3.+	Метод empty – возвращает true или false
//4.+	Метод push, чтобы положить в элемент в стек
//5.+	Метод pop, чтобы извлечь элемент из стека
//6.+   Метод top, чтобы посмотреть верхний элемент стека, но не извлекать его.
//
//Добавьте обработку некорректных ситуаций через исключения :
//1.????	Невозможно выделить необходимый участок памяти под стек(std::bad_alloc).
//2.+   Невозможно добавить новый элемент в стек(например, std::overflow_error)
//3.+	Невозможно извлечь элемент из стека, так как стек пустой(например, std::out_of_range)
//4.+	Невозможно посмотреть элемент на вершине стека, так как стек пустой(например, std::logic_error).
//
//Продемонстрируйте работу вашего стека.


#include <iostream>
template<typename T, int capacity>
class stek
{
private:
    int m_capacity = capacity;
    T* ptr;
    int cur_size = 0;
public:
    stek()
    {
        ptr = new T[m_capacity];
        throw "std::bad_alloc";

    }
    ~stek()
    {
        delete[] ptr;
    }
    
    int size()
    {
        return cur_size;
    }

    bool empty()
    {
        if (cur_size == 0) { return true; }
        else { return false; }
    }

    T top() 
    {
        if (cur_size == 0)
        {
            throw "Empty stek ";
        }
        return ptr[0];   
    }

    void push(T element)
    {
        if ((m_capacity - 1) < (cur_size)) { throw "Stek owerflow "; }
        ptr[cur_size] = element;
        cur_size += 1;
    }

    T pop()
    {
        if (cur_size < 1) { throw "Stek out of range "; }
        T elem = ptr[cur_size - 1];
        ptr[cur_size - 1] = 0;
        cur_size -= 1;
        return elem;
    }
};

int main()
{
    stek<int, 6> s;
    /*try 
    {
        stek<int, 6> s;

    }
    catch (const char* e)
    {
        std::cout << "err: ";
    }*/

    try
    {
        std::cout << s.top() << std::endl;
    }
    catch (const char* e)
    {
        std::cout << "std::logic_error: " << e << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        int k;
        std::cin >> k;
        try
        {
            s.push(k);
        }
        catch (const char* e)
        {
            std::cout << "overflow_error: " << e << std::endl;
            break;
        }
    }

    std::cout << "empty: " << s.empty() << std::endl;

    try
    {
        std::cout << s.top() << std::endl;
    }
    catch (const char* e)
    {
        std::cout << "std::logic_error: " << e << std::endl;
    }

    for (int i = 0; i < 6; i++)
    {
        try
        {
            std::cout << s.pop() << " ";
        }
        catch (const char* e)
        {
            std::cout << "std::out_of_range error: " << e << std::endl;
            break;
        }
    }
}

