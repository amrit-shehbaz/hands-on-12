#include <iostream>
#include <stdexcept> 

class DynamicArray {
private:
    int* data;         
    size_t capacity;    
    size_t size;     

public:
    // Constructor
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    // Destructor
    ~DynamicArray() {
        delete[] data;  
    }

    void push_back(int value) {
        if (size >= capacity) {
           
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_data = new int[new_capacity];

           
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

           
            delete[] data;

            
            data = new_data;
            capacity = new_capacity;
        }

        // Add the new element at the end
        data[size++] = value;
    }

     int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

     size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    // Example usage of DynamicArray
    DynamicArray arr;

    // Add elements to the array
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i * 2);
    }

    // Access and print elements using []
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
