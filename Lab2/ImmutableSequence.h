#ifndef IMMUTABLE_SEQUENCE_H
#define IMMUTABLE_SEQUENCE_H

template <typename T>
class ImmutableSequence {
public:
    virtual ~ImmutableSequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;

    virtual ImmutableSequence<T>* Append(T item) const = 0;
    virtual ImmutableSequence<T>* Prepend(T item) const = 0;
    virtual ImmutableSequence<T>* InsertAt(int index, T item) const = 0;
    virtual ImmutableSequence<T>* GetSubsequence(int start, int end) const = 0;
    virtual ImmutableSequence<T>* Concat(const ImmutableSequence<T>* other) const = 0;
};

#endif