#pragma once
#include <iostream>

class List
{

public:


    using ElementType = int;

    struct Node
    {
        Node() = default;
        Node(ElementType, Node*);

        ElementType value;
        Node* next;
    };

    List() = default;

    void push_back(const ElementType &value);

    void push_front(const ElementType &value);

    void erase(const ElementType &value);

    bool empty() const;

    size_t size() const;

    Node* find(ElementType value);

    void clear();

    friend std::ostream& operator<<(std::ostream&, const List&);
private:

    Node* first_element = nullptr;

};

std::ostream& operator<<(std::ostream&, const List&);
