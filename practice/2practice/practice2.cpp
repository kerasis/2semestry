#include <iostream>

const int SIZE = 100;

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


void mem_copy(void* destination, const void* source, int size) {

    unsigned char* _source = (unsigned char*)source;
    unsigned char* _destination = (unsigned char*)destination;
    //преобразовываем указательи void в char для разбиения памяти побайтово(что будет полезно для цикла с копированием остатка памяти)
    int len;

    for (len = size / 4; len--; _source += 4, _destination += 4) //итераций данного цикла будет 1/4 от size, здесь мы копируем большую часть всех данных по 4 байта 
        *(int*)_destination = *(int*)_source;
    len = size % 4;
    while (len--) //остаток не скопированной памяти копируется по 1 байту (в данном случае максимум 3 итерации цикла)
        *_destination++ = *_source++;
}


int main()
{
    int ar1[SIZE] = { 1,4,30122313,3123131 };
    int ar2[SIZE] = { 0 };

    float ar3[SIZE] = { 1.5, 2.2, 3.3, 4.234234 };
    float ar4[SIZE] = { 0 };

    mem_copy(&ar2, &ar1, sizeof(ar1));
    mem_copy(&ar4, &ar3, sizeof(ar3));

    std::cout << "pointer arr1: " << ar1 << std::endl;
    std::cout << "pointer arr2: " << ar2 << std::endl;

    show_ar(ar1, ar2); 
    show_ar(ar3, ar4);
}