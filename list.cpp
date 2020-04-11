#include "list.h"

void List::push_back(const ElementType &value)
{
    Node* new_last = new Node;

    new_last->value = value;
    new_last->next = nullptr;

    if (!elements)
    {
        elements = new_last;
        return;
    }

    Node* iterator = elements;
    while (iterator->next)
    {
        iterator = iterator->next;
    }

    iterator->next = new_last;
}

void List::erase(const ElementType &value)
{
    Node* iterator = elements;
    Node* previous;

    while (iterator && iterator->value != value)
    {
        previous = iterator;
        iterator = iterator->next;
    }

    if(!iterator)
    {
        return;
    }

    Node* tmp = iterator->next;

    delete iterator;
    previous->next = tmp;
}

// TODO написать метод вывода списка (попробывать перегрузку оператора вывода по аналогии с вектором)
// понять, в каких ситуациях не работает erase



