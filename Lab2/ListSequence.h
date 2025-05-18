#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:

    ListSequence() = default;
    ListSequence(T* items, int count) : list(items, count) {}
    ListSequence(const LinkedList<T>& linkedList) : list(linkedList) {}

    // Базовые операции Sequence
    T Get(int index) const override { return list.Get(index); }
    int GetLength() const override { return list.GetLength(); }
    T GetFirst() const override { return list.GetFirst(); }
    T GetLast() const override { return list.GetLast(); }
    ListSequence<T>* GetSubsequence(int start, int end) const override;
    ListSequence<T>* Concat(Sequence<T>* other) const override;

    // Изменяемые операции
    void Set(int index, T value) override { list.Set(index, value); }
    void Append(T item) override { list.Append(item); }
    void InsertAt(int index, T item) override { list.InsertAt(index, item); }
    void Prepend(T item) override { list.Prepend(item); }

};

#endif