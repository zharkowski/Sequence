#include "list.hpp"

template <class TElement>
ListSequence<TElement>::ListSequence() {
    this->Length = 0;
    head = NULL;
    tail = NULL;
}

template <class TElement>
ListSequence<TElement>::~ListSequence() {
    while (this->Length > 0) {
        RemoveByIndex(0);
    }
}

template <class TElement>
TElement ListSequence<TElement>::Get(int index) {
    if ((index >= this->Length) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    Node<TElement>* current_node = head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    
    return current_node->data;
}

template <class TElement>
TElement ListSequence<TElement>::GetFirst() {
    Node<TElement>* current_node = head;
    return current_node->data;
}

template <class TElement>
TElement ListSequence<TElement>::GetLast() {
    Node<TElement>* current_node = tail;
    return current_node->data;
}

template <class TElement>
void ListSequence<TElement>::Append(TElement item) {
    Node<TElement>* new_node = new Node<TElement>;
    new_node->data = item;
    
    if (this->Length == 0){
        head = new_node;
    }
    else {
        tail->next = new_node;
    }
    
    tail = new_node;
    
    (this->Length)++;
}

template <class TElement>
void ListSequence<TElement>::Prepend(TElement item) {
    Node<TElement>* new_node = new Node<TElement>;
    new_node->data = item;
    new_node->next = head;
    
    head = new_node;
    if (this->Length == 0){
        tail = new_node;
    }
    
    (this->Length)++;
}

template <class TElement>
void ListSequence<TElement>::InsertAt(int index, TElement item) {
    if ((index > this->Length) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    if (index == 0) {
        Prepend(item);
        return;
    }
    if (index == this->Length) {
        Append(item);
        return;
    }
    
    Node<TElement>* new_node = new Node<TElement>;
    new_node->data = item;
    
    Node<TElement>* current_node = head;
    for (int i = 0; i < index - 1; i++) {
        current_node = current_node->next;
    }
    
    new_node->next = current_node->next;
    current_node->next = new_node;
    
    (this->Length)++;
}

template <class TElement>
void ListSequence<TElement>::Remove(TElement item) {
    Node<TElement>* current_node = head;
    Node<TElement>* prev_node = head;
    
    for (int i = 0; i < this->Length; i++){
        if (current_node->data == item){
            if (i == 0){
                head = current_node->next;
            }
            if (i == this->Length - 1) {
                tail = prev_node;
            }
            
            prev_node->next = current_node->next;
            delete current_node;
            (this->Length)--;
            break;
        }
        
        prev_node = current_node;
        current_node = current_node->next;
    }
}

template <class TElement>
void ListSequence<TElement>::RemoveByIndex(int index) {
    if ((index >= this->Length) || (index < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    Node<TElement>* current_node = head;
    Node<TElement>* prev_node = head;
    
    for (int i = 0; i < index; i++) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    
    if (index == 0) {
        head = current_node->next;
    }
    
    if (index == this->Length - 1) {
        tail = prev_node;
    }
    
    prev_node->next = current_node->next;
    delete current_node;
    (this->Length)--;
}

template <class TElement>
ListSequence<TElement> ListSequence<TElement>::GetSubsequence(int beginIndex, int endIndex) {
    if (endIndex < beginIndex) {
        throw std::out_of_range("Out of range");
    }
    if ((beginIndex > this->Length) || (beginIndex < 0)) {
        throw std::out_of_range("Out of range");
    }
    if ((endIndex > this->Length) || (endIndex < 0)) {
        throw std::out_of_range("Out of range");
    }
    
    ListSequence<TElement> subseq;
    
    Node<TElement>* current_node = head;
    for (int i = 0; i < this->Length; i++) {
        if ((i >= beginIndex) && (i <= endIndex)) {
            subseq.Append(current_node->data);
        }
        current_node = current_node->next;
    }
    
    return subseq;
}
