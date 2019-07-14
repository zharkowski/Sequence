#include "array.hpp"

template <class TElement>
ArraySequence<TElement>::ArraySequence() {
    this->Length = 0;
    
    lengthLimit = 2;
    
    arrayPtr = new TElement[lengthLimit];
}

template <class TElement>
ArraySequence<TElement>::~ArraySequence() {
    while (this->Length > 0) {
        RemoveByIndex(0);
    }
}

template <class TElement>
TElement ArraySequence<TElement>::Get(int index) {
    if ((index >= this->getLength()) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    return arrayPtr[index];
}

template <class TElement>
TElement ArraySequence<TElement>::GetFirst() {
    return Get(0);
}

template <class TElement>
TElement ArraySequence<TElement>::GetLast() {
    return Get((this->Length) - 1);
}

template <class TElement>
void ArraySequence<TElement>::Append(TElement item) {
    InsertAt(this->Length, item);
}

template <class TElement>
void ArraySequence<TElement>::Prepend(TElement item) {
    InsertAt(0, item);
}

template <class TElement>
void ArraySequence<TElement>::InsertAt(int index, TElement item) {
    if ((index > this->Length) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }

    //если массив заполнен, то заменяем его на больший
    if (this->Length + 1 > lengthLimit) {
        TElement tempArr[this->Length];

        for (int i = 0; i < this->Length; i++) {
            tempArr[i] = arrayPtr[i];
        }

        delete [] arrayPtr;

        lengthLimit *= 2;
        arrayPtr = new TElement[lengthLimit];

        for (int i = 0; i < this->Length; i++) {
            arrayPtr[i] = tempArr[i];
        }
    }

    //смещаем все элементы вправо с конца до элемента с номером index
    for (int i = this->Length - 1; i >= index; i--){
        arrayPtr[i+1] = arrayPtr[i];
    }

    arrayPtr[index] = item;
    (this->Length)++;
}

template <class TElement>
void ArraySequence<TElement>::Remove(TElement item) {
    for (int i = 0; i < this->Length; i++) {
        if (item == arrayPtr[i]) {
            RemoveByIndex(i);
            break;
        }
    }
}

template <class TElement>
void ArraySequence<TElement>::RemoveByIndex(int index) {
    if ((index >= this->Length) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    //смещаем все элементы, начиная с номера index, влево до конца
    for (int i = index; i < (this->Length) - 1; i++) {
        arrayPtr[i] = arrayPtr[i+1];
    }
    
    arrayPtr[this->Length - 1] = NULL;
    this->Length--;
}

template <class TElement>
ArraySequence<TElement> ArraySequence<TElement>::GetSubsequence(int beginIndex, int endIndex) {
    if (endIndex < beginIndex) {
        throw std::out_of_range("Out of range");
    }
    if ((beginIndex > this->Length) || (beginIndex < 0)) {
        throw std::out_of_range("Out of range");
    }
    if ((endIndex > this->Length) || (endIndex < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    ArraySequence<TElement> subseq;
    for (int i = beginIndex; i <= endIndex; i++) {
        subseq.Append(Get(i));
    }
    
    return subseq;
}
