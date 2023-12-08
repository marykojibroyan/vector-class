#include "Vector.h"
#include <iostream>

int main() {

	Vector vec1;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

	std::cout << "vec1: " << vec1 << std::endl;

    Vector vec2(vec1);
	std::cout << "vec2 (copy of vec1): " << vec2 << std::endl;

    // Modify vec1
    vec1[0] = 100;
    vec1.push_back(40);

    std::cout << "vec1 (modified): " << vec1 << std::endl;
    std::cout << "vec2: " << vec2 << std::endl;

    // Demonstrate move semantics
    Vector vec3;
    vec3 = std::move(vec1);

    // Display vectors after move
    std::cout << "vec1 (after move): " << vec1 << std::endl; // Should be empty
    std::cout << "vec3 (after move): " << vec3 << std::endl;

    // Demonstrate pop_back, insert, and remove
    vec3.pop_back();
    std::cout << "vec3 (after pop_back): " << vec3 << std::endl;

    vec3.insert(1, 99);
    std::cout << "vec3 (after insert): " << vec3 << std::endl;

    vec3.remove(0);
    std::cout << "vec3 (after remove): " << vec3 << std::endl;

    return 0;
}


























