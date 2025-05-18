#include "ListSequence.h"

template <typename T>
ListSequence<T>* ListSequence<T>::GetSubsequence(int start, int end) const {
    LinkedList<T>* sublist = list.GetSubsequence(start, end);
    ListSequence<T>* result = new ListSequence<T>(*sublist);
    delete sublist;
    return result;
}

template <typename T>
ListSequence<T>* ListSequence<T>::Concat(Sequence<T>* other) const {
    LinkedList<T> newList(list);
    for (int i = 0; i < other->GetLength(); ++i) {
        newList.Append(other->Get(i));
    }
    return new ListSequence<T>(newList);
}

// явное инстанцирование
template class ListSequence<int>;
template class ListSequence<float>;
template class ListSequence<double>;