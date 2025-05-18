#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::LinkedList(T* items, int count) : LinkedList() {
    for (int i = 0; i < count; ++i) {
        Append(items[i]);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : LinkedList() {
    Node* current = other.head;
    while (current != nullptr) {
        Append(current->data);
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clearNodes();
}

template <typename T>
void LinkedList<T>::clearNodes() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getNode(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

template <typename T>
T LinkedList<T>::Get(int index) const {
    return getNode(index)->data;
}

template <typename T>
int LinkedList<T>::GetLength() const {
    return size;
}

template <typename T>
T LinkedList<T>::GetFirst() const {
    if (size == 0) throw std::out_of_range("List is empty");
    return head->data;
}

template <typename T>
T LinkedList<T>::GetLast() const {
    if (size == 0) throw std::out_of_range("List is empty");
    return tail->data;
}

template <typename T>
void LinkedList<T>::Set(int index, T value) {
    getNode(index)->data = value;
}

template <typename T>
void LinkedList<T>::Append(T item) {
    Node* newNode = new Node(item, tail);
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::Prepend(T item) {
    Node* newNode = new Node(item, nullptr, head);
    if (head) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::InsertAt(int index, T item) {
    if (index == 0) {
        Prepend(item);
    }
    else if (index == size) {
        Append(item);
    }
    else {
        Node* nextNode = getNode(index);
        Node* prevNode = nextNode->prev;
        Node* newNode = new Node(item, prevNode, nextNode);
        prevNode->next = newNode;
        nextNode->prev = newNode;
        size++;
    }
}

template <typename T>
void LinkedList<T>::RemoveAt(int index) {
    Node* nodeToRemove = getNode(index);

    if (nodeToRemove->prev) {
        nodeToRemove->prev->next = nodeToRemove->next;
    }
    else {
        head = nodeToRemove->next;
    }

    if (nodeToRemove->next) {
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
    else {
        tail = nodeToRemove->prev;
    }

    delete nodeToRemove;
    size--;
}

template <typename T>
LinkedList<T>* LinkedList<T>::GetSubsequence(int start, int end) const {
    if (start < 0 || end >= size || start > end) {
        throw std::out_of_range("Invalid subsequence range");
    }

    LinkedList<T>* result = new LinkedList<T>();
    Node* current = getNode(start);
    for (int i = start; i <= end; ++i) {
        result->Append(current->data);
        current = current->next;
    }
    return result;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(Sequence<T>* other) const {
    LinkedList<T>* result = new LinkedList<T>(*this);

    for (int i = 0; i < other->GetLength(); ++i) {
        result->Append(other->Get(i));
    }

    return result;
}

template <typename T>
void LinkedList<T>::Clear() {
    clearNodes();
}

// явное инстанцирование
template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;