#include "sorting.hpp"

template <template<class> class SequenceType, class TElement>
void mergeSort(SequenceType<TElement> &seq) {
    mergeSort(seq, 0, seq.getLength() -1);
}

template <template<class> class SequenceType, class TElement>
void mergeSort(SequenceType<TElement> &seq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;
        
        mergeSort(seq, left, mid);
        mergeSort(seq, mid+1, right);
        
        merge(seq, left, mid, right);
    }
    else return;
}

template <template<class> class SequenceType, class TElement>
void merge(SequenceType<TElement> &seq, int left, int mid, int right) {
    int firstSeqLen = mid - left + 1;
    int secondSeqLen = right - mid;

    SequenceType<TElement> LeftSeq;
    SequenceType<TElement> RightSeq;

    int i = 0;
    int j = 0;

    while (i < firstSeqLen) {
        LeftSeq.Append(seq.Get(left + i));
        i++;
    }

    while (j < secondSeqLen) {
        RightSeq.Append(seq.Get(mid + 1 + j));
        j++;
    }

    i = 0;
    j = 0;
    int k = left;
    while ((i < firstSeqLen) && (j < secondSeqLen)) {
        if (LeftSeq.Get(i) <= RightSeq.Get(j)) {
            seq.RemoveByIndex(k);
            seq.InsertAt(k, LeftSeq.Get(i));
            i++;
        } else {
            seq.RemoveByIndex(k);
            seq.InsertAt(k, RightSeq.Get(j));
            j++;
        }

        k++;
    }

    while (i < firstSeqLen) {
        seq.RemoveByIndex(k);
        seq.InsertAt(k, LeftSeq.Get(i));
        i++; k++;
    }

    while (j < secondSeqLen) {
        seq.RemoveByIndex(k);
        seq.InsertAt(k, RightSeq.Get(j));
        j++; k++;
    }
}

template <template<class> class SequenceType, class TElement>
void insertionSort(SequenceType<TElement> &seq) {
    
    for (int i = 1; i < seq.getLength(); ++i) {
        int j = i - 1;
        int selected = seq.Get(i);
        
        //Находим ячейку, в которую нужно вставить элемент
        int loc = binarySearch(seq, selected, 0, j);
        
        //Передвигаем все элементы после этой ячейки вправо
        for (;j >= loc; j--) {
            seq.swap(j,j+1);
        }
        
        seq.resetByIndex(j+1, selected);
    }
}

template <template<class> class SequenceType, class TElement>
int binarySearch(SequenceType<TElement> &seq, TElement item, int low, int high) {
    if (high <= low)
        return (item > seq.Get(low)) ?  (low + 1): low;
    
    int mid = (low + high)/2;
    
    if (item == seq.Get(mid))
        return mid+1;
    
    if (item > seq.Get(mid))
        return binarySearch(seq, item, mid+1, high);
    return binarySearch(seq, item, low, mid-1);
}
