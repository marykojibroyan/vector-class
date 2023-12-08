#include "Vector.h"

Vector::Vector() 
   	: size(0)
	, capacity(0) 
	, data(nullptr)
{}

Vector::Vector(int iSize) 
	: size(iSize)
{}

Vector::Vector(const Vector& other) 
	: size(other.size)
	, capacity(other.capacity) 
	, data(new int[capacity])
   {
	   for (int i = 0; i < size; ++i)
	   {
		data[i] = other.data[i];
	   }	
   }

Vector::Vector(Vector&& other) noexcept 
	: data(other.data)
	, size(other.size)
	, capacity(other.capacity) 
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

}

Vector::~Vector() {
    delete[] data;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
		
			for (int i = 0; i < size; ++i)
			{
				data[i] = other.data[i];
			}
	}
    return *this;
}


Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;
     
	 	other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

int& Vector::operator[](int pos) const {
    if (pos < 0 || pos >= size) 
	{
  		throw std::out_of_range("Index out of bounds");
    }
	return data[pos];
}

int Vector::Size() const
{
	return size;
}

void Vector::push_back(int value) {
    if (size == capacity)
    {
        resize();
    }
    data[size++] = value;
}

void Vector::push_front(int value) {
    
    if (size == capacity) 
    {
        resize();
    }
        for (int i = size; i > 0; --i)
        {
            data[i] = data[i - 1];
        }

        data[0] = value;

        ++size;
    }

void Vector::pop_back() {
    if (size > 0) {
        --size;
    }
}

void Vector::resize() {
     
    capacity = (capacity == 0) ? 1 : capacity * 2;

        int* newData = new int[capacity];
       
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    
void Vector::insert(int index, int value) {
    if (index > size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (size == capacity)
    {
        resize();
    }
        
   	else {
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }
}

void Vector::remove(int index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size;
}


int Vector::getSize() const {
    return size;
}

int Vector::getCapacity() const {
    return capacity;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec)
   {
       for (int i = 0; i < vec.Size(); ++i)
       {
           out << vec[i];
      }
  return out;
 }





