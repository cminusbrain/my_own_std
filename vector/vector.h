#pragma once

#include <iostream>
#include <cstdint>

typedef int ElementType;

class Vector
{
public:

    Vector();

    explicit Vector(size_t size);

    Vector(const Vector &another);

    Vector(ElementType* begin, ElementType* end);

    ~Vector();

    void print() const;

    void push_back(ElementType value);

    size_t get_size() const;

    void BubbleSort();

    ElementType* data() const;

    bool is_empty() const;

    void clear();

    void insert(size_t position, int elem);

    void erase(size_t position);

    ElementType & operator[](size_t index) const;

    bool operator== (const Vector &another) const;

    bool operator!= (const Vector &another) const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
private:
    size_t size_;
    ElementType *elements;
};

std::ostream& operator<<(std::ostream& out, const Vector& v);