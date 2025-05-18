#include "DynamicArray.h"
#include <algorithm>

template <typename T>
void DynamicArray<T>::ValidateIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
}

// ������������
template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(T* items, int count) : DynamicArray() {
    if (count < 0) throw std::invalid_argument("Negative size");
    Reserve(count);
    for (int i = 0; i < count; ++i) data[i] = items[i];
    size = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) : DynamicArray() {
    if (size < 0) throw std::invalid_argument("Negative size");
    Reserve(size);
    this->size = size;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : DynamicArray() {
    Reserve(other.size);
    for (int i = 0; i < other.size; ++i) data[i] = other.data[i];
    size = other.size;
}

// ����������
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

// �������� ������������
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if (this != &other) {
        DynamicArray<T> tmp(other);
        std::swap(data, tmp.data);
        std::swap(size, tmp.size);
        std::swap(capacity, tmp.capacity);
    }
    return *this;
}

// ������ �������
template <typename T>
T DynamicArray<T>::Get(int index) const {
    ValidateIndex(index);
    return data[index];
}

template <typename T>
int DynamicArray<T>::GetLength() const {
    return size;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    ValidateIndex(index);
    data[index] = value;
}

// ������ �����������
template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize < 0) throw std::invalid_argument("Negative size");

    Reserve(newSize);

    // �������������� ����� �������� ������ (���� ������ ����������)
    if (newSize > size) {
        for (int i = size; i < newSize; ++i) {
            data[i] = T{}; // ������������� ������� �������������
        }
    }

    size = newSize;
}

template <typename T>
void DynamicArray<T>::Reserve(int newCapacity) {
    if (newCapacity <= capacity) return;

    T* newData = new T[newCapacity];
    for (int i = 0; i < size; ++i) newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::Append(T item) {
    if (size == capacity) Reserve(capacity ? capacity * 2 : 1);
    data[size++] = item;
}