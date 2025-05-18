#pragma once
#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "MutableSequence.h"
#include "DynamicArray.h"

template <typename T>
class ArraySequence : public MutableSequence<T> {
private:
    DynamicArray<T> array;

public:
    ArraySequence() = default;
    ArraySequence(T* items, int count) : array(items, count) {}
    ArraySequence(const DynamicArray<T>& dynamicArray) : array(dynamicArray) {}

    // Реализация Sequence
    T Get(int index) const override { return array.Get(index); }
    int GetLength() const override { return array.GetLength(); }
    T GetFirst() const override { return array.Get(0); }
    T GetLast() const override { return array.Get(array.GetLength() - 1); }
    ArraySequence<T>* GetSubsequence(int start, int end) const override;
    ArraySequence<T>* Concat(Sequence<T>* other) const override;

    // Реализация MutableSequence
    void Set(int index, T value) override { array.Set(index, value); }
    void Append(T item) override { array.Append(item); }
    void Prepend(T item) override;
    void InsertAt(int index, T item) override;
    void RemoveAt(int index) override;
};

#endif