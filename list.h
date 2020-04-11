#pragma once

class List
{
    using ElementType = int;
    struct Node
    {
        ElementType value;
        Node* next;
    };
public:

    List() = default;

    void push_back(const ElementType &value);

    void erase(const ElementType &value);
private:

    Node* elements = nullptr;

};
