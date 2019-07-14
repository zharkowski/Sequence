#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include "sequence.hpp"

template <class TElement>
struct Node {
    TElement data;
    Node* next;
};

template <class TElement>
class ListSequence : public Sequence<TElement> {
public:
    ListSequence();
    ~ListSequence();
        
    TElement Get (int index);
    TElement GetFirst ();
    TElement GetLast ();
    
    void Append(TElement item);
    void Prepend(TElement item);
    void InsertAt(int index, TElement item);
    void Remove(TElement item);
    void RemoveByIndex(int index);
    
    ListSequence<TElement> GetSubsequence(int beginIndex, int endIndex);   //получает подпоследовательность, начиная с beginIndex и заканчивая endIndex
        
private:
//    int length;
    Node<TElement>* head;
    Node<TElement>* tail;
};
#include "list.cpp"

#endif /* list_hpp */
