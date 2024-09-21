#include <iostream>

class Vector {
private:
    int* data;
    int size;

public:
    // Constructor
    Vector(int s) : size(s) {
        data = new int[size];
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Copy constructor (deep copy)
    Vector(const Vector& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator (deep copy)
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        delete[] data; // Free existing memory

        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Operator+ overloaded (deep copy)
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same length for addition.");
        }

        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // Method to set a value
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // Method to print the vector
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector vec1(3);
    vec1.setValue(0, 1);
    vec1.setValue(1, 2);
    vec1.setValue(2, 3);

    Vector vec2(3);
    vec2.setValue(0, 4);
    vec2.setValue(1, 5);
    vec2.setValue(2, 6);

    Vector vec3(3);  // Initialize vec3 as an empty vector of the same size

    // Perform the addition after vec3 has been initialized
    vec3 = vec1 + vec2;

    vec3.print();  // Should print the sum of vec1 and vec2

    return 0;
}