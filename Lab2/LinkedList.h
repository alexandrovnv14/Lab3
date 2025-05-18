#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "MutableSequence.h"

template <typename T>
class LinkedList : public MutableSequence<T> {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value, Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {
        }
    };

    Node* head;
    Node* tail;
    int size;

    void clearNodes();
    Node* getNode(int index) const;

public:
    LinkedList();
    LinkedList(T* items, int count);
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();

    // Базовые операции
    T Get(int index) const override;
    int GetLength() const override;
    T GetFirst() const override;
    T GetLast() const override;

    // Изменяемые операции
    void Set(int index, T value) override;
    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(int index, T item) override;
    void RemoveAt(int index) override;

    // Операции создания новых последовательностей
    LinkedList<T>* GetSubsequence(int start, int end) const override;
    LinkedList<T>* Concat(Sequence<T>* other) const override;

    // Дополнительные методы
    void Clear();
};

#endif