#include <iostream>

const int SIZE = 1000;
template<typename T>
void my_copy(T *mas1, T *mas2)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(mas2 + i) = *(mas1 + i);
    }
}

template<typename T>
void show_ar(T *mas1, T *mas2)
{
    for (int i = 0; i < SIZE; i++)
    {

        std::cout << mas1[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << mas2[i] << " ";
    }
    std::cout << "\n";
}
int main()
{
    int ar1[SIZE] = {1,4,67,3};
    int ar2[SIZE] = { 0 };
    my_copy(ar1, ar2);

    std::cout << "pointer arr1: " << ar1 << std::endl;
    std::cout << "pointer arr2: " << ar2 << std::endl;

    show_ar(ar1, ar2);
    
}


