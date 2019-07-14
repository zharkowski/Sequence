#ifndef array_hpp
#define array_hpp

#include "sequence.hpp"

template <class TElement>
class ArraySequence : public Sequence<TElement> {
public:
    ArraySequence();
    ~ArraySequence();

    TElement Get (int index);
    TElement GetFirst ();
    TElement GetLast ();

    void Append(TElement item);
    void Prepend(TElement item);
    void InsertAt(int index, TElement item);
    void Remove(TElement item);
    void RemoveByIndex(int index);

    ArraySequence<TElement> GetSubsequence(int beginIndex, int endIndex);   //получает подпоследовательность, начиная с beginIndex и заканчивая endIndex
        
private:
    int lengthLimit;
    TElement *arrayPtr;
};

#include "array.cpp"

#endif /* array_hpp */
