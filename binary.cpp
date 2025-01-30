#include <iostream>

using namespace std;

class Binary {
private:
    int x, y;

public:
    // Default constructor
    Binary() : x(1), y(0) {}

    // Parameterized constructor
    Binary(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Overloaded arithmetic assignment operator (*=)
    Binary& operator*=(const Binary& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    // Function to compare two Binary objects
    bool isEqual(const Binary& other) const {
        return (this->x == other.x && this->y == other.y);
    }

    // Function to get equal Binary objects
    static Binary* getEqualBinary(const Binary arr[], int size, int& newSize) {
        newSize = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[0].isEqual(arr[i])) {
                ++newSize;
            }
        }

        if (newSize == 0) {
            newSize = 0;
            return nullptr;
        }

        Binary* newArray = new Binary[newSize];
        int index = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[0].isEqual(arr[i])) {
                newArray[index++] = arr[i];
            }
        }
        return newArray;
    }
};

int main()
{
    Binary arr[] = {Binary(1, 0), Binary(1, 0), Binary(0, 1)};
    int size = 3;
    int newSize;

    Binary* equalArr = Binary::getEqualBinary(arr, size, newSize);

    if (equalArr == nullptr) {
        std::cout << "No equal Binary objects found." << std::endl;
    } else {
        std::cout << "Number of equal Binary objects: " << newSize << std::endl;
        for (int i = 0; i < newSize; ++i) {
            std::cout << "Equal Binary object found." << std::endl;
        }
        delete[] equalArr;
    }

    return 0;
}
