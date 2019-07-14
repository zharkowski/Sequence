#ifndef sequence_hpp
#define sequence_hpp
#include <iostream>

template <class TElement>
class Sequence {
protected:
    int Length;

public:    
    int getLength();
    int getIsEmpty();
    
    void swap(int indexA, int indexB);
    void resetByIndex(int index, TElement new_value);
    
    void print();
    
    virtual TElement Get (int index) = 0;   //получение элемента по индексу
    virtual TElement GetFirst () = 0;   //получение первого элемента
    virtual TElement GetLast () = 0;    //получение последнего элемента
    
    virtual void Append (TElement item) = 0;    //добавить элемент в конец последовательности
    virtual void Prepend (TElement item) = 0;   //добавить элемент в начало последовательности
    virtual void InsertAt (int index, TElement item) = 0;   //вставить элемент в позицию index
    virtual void Remove (TElement item) = 0;    //удаляет элемент item из последовательности
    virtual void RemoveByIndex (int index) = 0;  //удаляет элемент с индексом index
};

#include "sequence.cpp"

#endif /* sequence_hpp */
