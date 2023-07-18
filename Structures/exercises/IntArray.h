#pragma once
#include <iostream>

struct IntArray {
    //това няма място тук - капацитета е общ за всички обекти от структурата
    const int CAPACITY = 20;

    int elements[20] {};
    int size;
    //public е по подразбиране - спецификатора тук е излишен
    public: IntArray()
    {
        size = 0;
    }
    void add(int number)
    {
        elements[size++] = number;
    }
    int getSize()
    {
        return size;
    }
};

void addElemToArray(IntArray &array, int number)
{
    //if (array.size < array.CAPACITY) - нямаш нужда от равно, тъй като размера ти не е индекс. Като имаш 4 елемента при капацитет 5 и поискаш да добавиш още един,
    //програмата трябва да го позволи
    if(array.size + 1 < array.CAPACITY)
    {
        array.elements[array.size++] = number;
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return;
    }
}

void removeElemFromArray(IntArray &array, int index)
{
    //коментара за условието за валидност от долната функция важи и тук
    //също така, ако обхождаш до array.size-1 ще си спестиш едно присвояване
    if(array.size > 0 && index >= 0 && index < array.size)
    {
        for (int i = index; i < array.size; ++i)
        {
            array.elements[i] = array.elements[i + 1];
        }
        array.size--;
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return;
    }
}

int getArraySize(IntArray &array)
{
    return array.size;
}

int getArrayElem(IntArray &array, int index)
{
    //условията за коректност обикновено са най-горе във функцията, а не на последно място:
    //if (index < 0 || index >= array.size) {
    //  std::cerr<<"ERROR"<<<std::endl;
    //  return -1;
    //}
    //return array.elements[index];
    if(index < array.size && index >=0)
    {
        return array.elements[index];
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return -1;
    }
}

void testIntArray()
{
    IntArray array;
    addElemToArray(array, 4);
    array.add(5);
    for(int i = 0; i < array.getSize(); i++) {
        std::cout<<getArrayElem(array, i)<<" ";
    }
    //трябва да изведе: “4 5 ”
    //в условието в долните редове пише &array, не array - това ще промени сигнатурата и тялото и на трите функции. Иначе това, което си написал
    //ще изведе правилните неща
    removeElemFromArray(array, 0);
    std::cout<<getArraySize(array)<<std::endl; //трябва да изведе 1
    std::cout<<getArrayElem(array, 0)<<std::endl; //трябва да изведе 5
}
