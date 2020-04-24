#include <vector/vector.h>
#include <algorithm>

Vector::Vector() :
    size_(0),
    elements(nullptr)
{}

Vector::Vector(size_t size) :
    size_(size),
    elements(new ElementType[size])
{
    for (size_t i = 0; i < size; i++)
    {
        elements[i] = 0;
    }
}

Vector::Vector(const Vector &another) :
    size_(another.get_size()),
    elements(new ElementType[another.get_size()])
{
    for (size_t i = 0; i < size_; i++)
    {
        elements[i] = another[i];
    }
}

Vector::Vector(ElementType* begin, ElementType* end) :
    Vector()
{
    for(ElementType* pointer = begin; pointer != end; pointer++)
    {
        push_back(*pointer);
    }
}

Vector::~Vector()
{
    delete[] elements;
}

void Vector::print() const
{
    for (size_t i = 0; i < size_; i++)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::push_back(ElementType value)
{
    ElementType *tmp = new ElementType[size_ + 1];
    for (size_t i = 0; i < size_; i++)
    {
        tmp[i] = elements[i];
    }
    tmp[size_] = value;
    delete[] elements;
    elements = tmp;
    size_++;
}

size_t Vector::get_size() const
{
    return size_;
}

void Vector::BubbleSort()
{
    for (size_t i = 0; i < size_ - 1; i++)
    {
        for (size_t j = 0; j < size_; j++)
        {
            if (elements[j] < elements[j + 1])
            {
                int tmp = elements[j + 1];
                elements[j + 1] = elements[j];
                elements[j] = tmp;
            }
        }
    }
}

ElementType & Vector::operator[](size_t index) const
{
    return elements[index];
}

ElementType* Vector::data() const
{
    return elements;
}

bool Vector::is_empty() const
{
    return size_ == 0;
}

void Vector::clear()
{
    delete[] elements;
    size_ = 0;
    elements = nullptr;
}

void Vector::insert(size_t position, ElementType elem)
{
    ElementType* tmp = new ElementType[size_ + 1];
    for (size_t i = 0; i < position; i++)
    {
         tmp[i] = elements[i];
    }
    tmp[position] = elem;
    for (size_t i = position; i < size_; i++)
    {
        tmp[i + 1] = elements[i];
    }
    size_++;
    delete[] elements;
    elements = tmp;
}

void Vector::erase(size_t position)
{
    ElementType* tmp = new ElementType[size_ - 1];
    for (size_t i = 0; i < position; i++)
    {
        tmp[i] = elements[i];
    }
    for (size_t i = position; i < size_; i++)
    {
        tmp[i] = elements[i + 1];
    }
    --size_;
    delete[] elements;
    elements = tmp;
}

bool Vector::operator==(const Vector &another) const
{
    if (size_ != another.get_size())
    {
        return false;
    }
    for (size_t i = 0; i < size_; i++)
    {
        if (elements[i] != another[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector &another) const
{
    return !(operator==(another));
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    for (size_t i = 0; i < v.get_size(); ++i)
    {
        out << v[i] << ' ';
    }
    out << std::endl;
    return out;
}

void merge(Vector &m, size_t left, size_t right, size_t middle)
{
    if (left >= right || middle < left || middle > right) return;
    if (right == left + 1 && m[left] > m[right])
    {
        std::swap(m[left], m[right]);
        return;
    }

    Vector tmp(&m[left], &m[right] + 1);

    for (size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i)
    {
        if (j > middle - left)
        {
            m[i] = tmp[k++];
        }
        else if(k > right - left)
        {
            m[i] = tmp[j++];
        }
        else
        {
            m[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
        }
    }
}
void merge_sort(Vector &m, size_t left, size_t right)
{

    if(left >= right) return;

    size_t middle = left + (right - left) / 2;

    merge_sort(m, left, middle);
    merge_sort(m, middle + 1, right);
    merge(m, left, right, middle);
}
