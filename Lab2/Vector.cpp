#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"

template <typename T>
Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

template <typename T>
void Vector<T>::resize(int new_capacity) {
    if (new_capacity < size_) new_capacity = size_;
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size_; ++i)
        new_data[i] = data_[i];
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
int Vector<T>::GetLength() const {
    return size_;
}

template <typename T>
T Vector<T>::Get(int index) const {
    if (index < 0 || index >= size_) throw std::out_of_range("Index out of bounds");
    return data_[index];
}

template <typename T>
T Vector<T>::GetFirst() const {
    return Get(0);
}

template <typename T>
T Vector<T>::GetLast() const {
    return Get(size_ - 1);
}

template <typename T>
Sequence<T>* Vector<T>::GetSubsequence(int start, int end) const {
    if (start < 0 || end > size_ || start > end)
        throw std::out_of_range("Invalid subsequence range");
    Vector<T>* subseq = new Vector<T>();
    for (int i = start; i < end; ++i)
        subseq->Append(data_[i]);
    return subseq;
}

template <typename T>
Sequence<T>* Vector<T>::Concat(Sequence<T>* other) const {
    Vector<T>* result = new Vector<T>(*this);
    for (int i = 0; i < other->GetLength(); ++i)
        result->Append(other->Get(i));
    return result;
}

template <typename T>
void Vector<T>::Set(int index, T value) {
    if (index < 0 || index >= size_) throw std::out_of_range("Index out of bounds");
    data_[index] = value;
}

template <typename T>
void Vector<T>::Append(T item) {
    if (size_ == capacity_) resize(capacity_ == 0 ? 1 : capacity_ * 2);
    data_[size_++] = item;
}

template <typename T>
void Vector<T>::InsertAt(int index, T item) {
    if (index < 0 || index > size_) throw std::out_of_range("Index out of bounds");
    if (size_ == capacity_) resize(capacity_ == 0 ? 1 : capacity_ * 2);
    for (int i = size_; i > index; --i)
        data_[i] = data_[i - 1];
    data_[index] = item;
    ++size_;
}

template <typename T>
void Vector<T>::Prepend(T item) {
    InsertAt(0, item);
}

#endif