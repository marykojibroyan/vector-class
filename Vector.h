#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include <iostream>

class Vector {
public:
    Vector();
    Vector(int iSize);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;

    int& operator[](int pos) const;
   	int Size() const;

	void push_back(int value);
    void pop_back();
    void push_front(int value);
    void insert(int index, int value);
    void remove(int index);

    int getSize() const;
    int getCapacity() const;

private:
	int size;
	int capacity;
	int* data;

    void resize();
};
std::ostream& operator<<(std::ostream& out, const Vector& vec);

#endif // VECTOR_H

