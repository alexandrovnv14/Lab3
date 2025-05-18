#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "ArraySequence.h"

#include <locale.h>

using namespace std;

void printSectionHeader(const string& title) {
    cout << "\n─── " << title << " ───" << endl;
}

template<typename T>
void printContainer(const string& name, const T& container) {
    cout<< name << ": " << "[";
    for (int i = 0; i < container.GetLength(); ++i) {
        cout << container.Get(i);
        if (i != container.GetLength() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void testDynamicArray() {
    printSectionHeader("DynamicArray DEMO");

    // 1. Создание и заполнение
    DynamicArray<int> arr(5);
    for (int i = 0; i < 5; ++i) arr.Set(i, (i + 1) * 10);
    printContainer("Исходный массив", arr);

    // 2. Изменение элемента
    arr.Set(2, 999);
    printContainer("После Set(2, 999)", arr);

    // 3. Resize
    arr.Resize(7);
    printContainer("После Resize(7)", arr);

    // 4. Копирование
    DynamicArray<int> arrCopy(arr);
    printContainer("Копия массива", arrCopy);
}

void testLinkedList() {
    printSectionHeader("LinkedList DEMO");

    // 1. Создание из массива
    int initData[] = { 10, 20, 30, 40 };
    LinkedList<int> list(initData, 4);
    printContainer("Созданный список", list);

    // 2. Добавление элементов
    list.Append(50);
    list.Prepend(5);
    printContainer("После Append(50) и Prepend(5)", list);

    // 3. Вставка/удаление
    list.InsertAt(2, 15);
    list.RemoveAt(3);
    printContainer("После InsertAt(2,15) и RemoveAt(3)", list);

    // 4. Подпоследовательность
    auto sublist = list.GetSubsequence(1, 3);
    printContainer("Подпоследовательность [1:3]", *sublist);
    delete sublist;
}

void testListSequence() {
    printSectionHeader("ListSequence DEMO");

    // 1. Создание последовательности
    ListSequence<int> seq;
    seq.Append(100);
    seq.Append(200);
    seq.Prepend(50);
    printContainer("Инициализированная последовательность", seq);

    // 2. Вставка
    seq.InsertAt(2, 150);
    printContainer("После InsertAt(2, 150)", seq);

    // 3. Конкатенация
    ListSequence<int> seq2;
    seq2.Append(300);
    seq2.Append(400);
    auto combined = seq.Concat(&seq2);
    printContainer("Результат конкатенации", *combined);
    delete combined;
}

void testArraySequence() {
    printSectionHeader("ArraySequence DEMO");

    // 1. Создание из массива
    int initData[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(initData, 5);
    printContainer("Исходная последовательность", arrSeq);

    // 2. Модификации
    arrSeq.RemoveAt(1);
    arrSeq.InsertAt(0, 99);
    printContainer("После RemoveAt(1) и InsertAt(0,99)", arrSeq);

    // 3. Подпоследовательность
    auto subseq = arrSeq.GetSubsequence(1, 3);
    printContainer("Подпоследовательность [1:3]", *subseq);
    delete subseq;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "===== ТЕСТИРОВАНИЕ КОЛЛЕКЦИЙ =====" << endl;

    testDynamicArray();
    testLinkedList();
    testListSequence();
    testArraySequence();

    cout << "\nВсе тесты завершены!" << endl;
    return 0;
}