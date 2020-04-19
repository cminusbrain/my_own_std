#include "list.h"

List::Node::Node(ElementType value, Node* ptr)
{
    this->value = value;
    this->next = ptr;
}

void List::push_back(const ElementType &value)
{
    Node* new_last = new Node(value, nullptr);

    if (!first_element)
    {
        first_element = new_last;
        return;
    }

    Node* iterator = first_element;
    while (iterator->next)
    {
        iterator = iterator->next;
    }

    iterator->next = new_last;
}

void List::push_front(const ElementType &value)
{
    Node *new_first = new Node(value, first_element);

    first_element = new_first;
}

void List::erase(const ElementType &value)
{
    Node* iterator = first_element;
    Node* previous = nullptr;

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
    if (previous)
    {
        previous->next = tmp;
    }
    else
    {
        first_element = tmp;
    }
}

bool List::empty() const
{
    return first_element == nullptr;
}


size_t List::size() const
{
    size_t counter = 0;
    Node* iterator = this->first_element;
    while (iterator)
    {
        iterator = iterator->next;
        counter++;
    }
    return counter;
}

List::Node* List::find(ElementType value)
{
    List::Node* iterator = first_element;
    while (iterator && value == iterator->value)
    {
        iterator = iterator->next;
    }
    return iterator;
}

void List::clear()
{
    Node* iterator = first_element;
    while (iterator)
    {
        auto tmp = iterator;
        iterator = iterator->next;
        delete tmp;
    }
    first_element = nullptr;
}



std::ostream& operator<<(std::ostream& out, const List& list)
{
    List::Node* iterator = list.first_element;
    while (iterator)
    {
        out << iterator->value << " ";
        iterator = iterator->next;
    }
    out << std::endl;
    return out;
}

// TODO: Написать конструктор для класса List с параметром типа Vector



