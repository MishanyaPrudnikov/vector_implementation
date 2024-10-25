#pragma once

#include <cstdlib>
#include <stdexcept>

template<typename T>
class Vector {
public:
    Vector();
    ~Vector();
    void push_back(const T& value);
    T& operator[](size_t index);
    size_t size() const;
    bool empty() const;

private:
    T* data;
    size_t capacity;
    size_t count;
    void resize(size_t new_capacity);
};

template<typename T>
Vector<T>::Vector() : capacity(1), count(0) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (count == capacity) {
        resize(capacity * 2);
    }
    data[count++] = value;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t Vector<T>::size() const {
    return count;
}

template<typename T>
bool Vector<T>::empty() const {
    return count == 0;
}

template<typename T>
void Vector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < count; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}


