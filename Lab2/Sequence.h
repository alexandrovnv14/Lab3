#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence {
public:
    virtual ~Sequence() = default;

    // Базовые операции (чисто виртуальные)
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual Sequence<T>* GetSubsequence(int start, int end) const = 0;
    virtual Sequence<T>* Concat(Sequence<T>* other) const = 0;

    // Изменяемые операции (должны быть чисто виртуальными для MutableSequence)
    virtual void Set(int index, T value) = 0;
    virtual void Append(T item) = 0;
    virtual void InsertAt(int index, T item) = 0;
    virtual void Prepend(T item) = 0;
};

#endif