#ifndef sorting_hpp
#define sorting_hpp

#include "../sequence/sequence.hpp"

template <template<class> class SequenceType, class TElement>
void mergeSort(SequenceType<TElement> &seq);

template <template<class> class SequenceType, class TElement>
void mergeSort(SequenceType<TElement> &seq, int left, int right);

template <template<class> class SequenceType, class TElement>
void merge(SequenceType<TElement> &seq, int left, int mid, int right);

template <template<class> class SequenceType, class TElement>
int binarySearch(SequenceType<TElement> &seq, TElement key, int l, int r);

template <template<class> class SequenceType, class TElement>
void insertionSort(SequenceType<TElement> &seq);

#include "sorting.cpp"

#endif /* sorting_hpp */
