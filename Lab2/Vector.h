#ifndef VECTOR_H
#define VECTOR_H

#include "sequence.h"
#include <stdexcept>

template <typename T>
class Vector : public Sequence<T> {
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    ~Vector();

    // Реализация чисто виртуальных методов Sequence
    T Get(int index) const override;
    int GetLength() const override;
    T GetFirst() const override;
    T GetLast() const override;
    Sequence<T>* GetSubsequence(int start, int end) const override;
    Sequence<T>* Concat(Sequence<T>* other) const override;

    void Set(int index, T value) override;
    void Append(T item) override;
    void InsertAt(int index, T item) override;
    void Prepend(T item) override;

private:
    T* data_;
    int size_;
    int capacity_;

    void resize(int new_capacity);
};

#endif