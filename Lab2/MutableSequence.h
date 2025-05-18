#ifndef MUTABLE_SEQUENCE_H
#define MUTABLE_SEQUENCE_H

#include "Sequence.h"

template <typename T>
class MutableSequence : public Sequence<T> {
public:
    // �������������� ���������� ������
    void Set(int index, T value) override = 0;
    void Append(T item) override = 0;
    void InsertAt(int index, T item) override = 0;
    virtual void RemoveAt(int index) = 0;

    // ��������� ������
    static MutableSequence<T>* CreateEmpty();
    static MutableSequence<T>* CreateFromArray(T* items, int count);
};

#endif