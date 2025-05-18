#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>

template <typename T>
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(T* items, int count);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray();

    DynamicArray<T>& operator=(const DynamicArray<T>& other);

    T Get(int index) const;
    int GetLength() const;
    void Set(int index, T value);

    void Resize(int newSize);
    void Reserve(int newCapacity);
    void Append(T item);

private:
    T* data;
    int size;
    int capacity;
    void ValidateIndex(int index) const;
};

// явное инстанцирование дл€ распространЄнных типов
template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<double>;


#endif