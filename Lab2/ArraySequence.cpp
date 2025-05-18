#include "ArraySequence.h"

template <typename T>
void ArraySequence<T>::Prepend(T item) {
    array.Resize(array.GetLength() + 1);
    for (int i = array.GetLength() - 1; i > 0; --i) {
        array.Set(i, array.Get(i - 1));
    }
    array.Set(0, item);
}

template <typename T>
void ArraySequence<T>::InsertAt(int index, T item) {
    if (index == 0) {
        Prepend(item);
    }
    else if (index == array.GetLength()) {
        Append(item);
    }
    else {
        array.Resize(array.GetLength() + 1);
        for (int i = array.GetLength() - 1; i > index; --i) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(index, item);
    }
}

template <typename T>
void ArraySequence<T>::RemoveAt(int index) {
    for (int i = index; i < array.GetLength() - 1; ++i) {
        array.Set(i, array.Get(i + 1));
    }
    array.Resize(array.GetLength() - 1);
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::GetSubsequence(int start, int end) const {
    DynamicArray<T> subarray(end - start + 1);
    for (int i = start; i <= end; ++i) {
        subarray.Set(i - start, array.Get(i));
    }
    return new ArraySequence<T>(subarray);
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Concat(Sequence<T>* other) const {
    DynamicArray<T> newArray(array);
    newArray.Resize(array.GetLength() + other->GetLength());
    for (int i = 0; i < other->GetLength(); ++i) {
        newArray.Set(array.GetLength() + i, other->Get(i));
    }
    return new ArraySequence<T>(newArray);
}

template class ArraySequence<int>;
template class ArraySequence<float>;
template class ArraySequence<double>;