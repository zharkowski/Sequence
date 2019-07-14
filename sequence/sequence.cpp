#include "sequence.hpp"

template <class TElement>
int Sequence<TElement>::getLength() {
    return this->Length;
}

template <class TElement>
int Sequence<TElement>::getIsEmpty() {
    return (this->Length == 0);
}

template <class TElement>
void Sequence<TElement>::swap(int indexA, int indexB) {
    TElement elemA = this->Get(indexA);
    TElement elemB = this->Get(indexB);
    
    this->RemoveByIndex(indexA);
    this->InsertAt(indexA, elemB);
    
    this->RemoveByIndex(indexB);
    this->InsertAt(indexB, elemA);
}

template <class TElement>
void Sequence<TElement>::resetByIndex(int index, TElement new_value) {
    this->RemoveByIndex(index);
    this->InsertAt(index, new_value);
}

template <class TElement>
void Sequence<TElement>::print() {
    for (int i = 0; i < this->getLength(); i++){
        std::cout<<this->Get(i)<<" ";
    }
    std::cout<<std::endl;
}
