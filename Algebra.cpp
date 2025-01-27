#include <iostream>
using namespace std;

class Algebra {
private:
	int a, b;
	
public:
	// Default constructor
	Algebra() : a(0), b(0) {}
	
	// Parameterized constructor
	Algebra(int x, int y) : a(x > 0 ? x : 0), b(y > 0 ? y : 0) {}
	
	// Getter methods
	int getA() const { return a; }
	int getB() const { return b; }
	
	// Setter methods
	void setA(int x) { a = x > 0 ? x : 0; }
	void setB(int y) { b = y > 0 ? y : 0; }
	
	// Stream extraction operator overloading
	friend std::istream& operator>>(std::istream &in, Algebra &obj);
	
	// Equality operator overloading for comparison
	bool operator==(const Algebra &other) const {
		return a == other.a && b == other.b;
	}
	
	// Method to get different objects
	Algebra* getDifferentObjects(const Algebra arr[], int size, int &newSize) const;
};

// Stream extraction operator definition
std::istream& operator>>(std::istream &in, Algebra &obj) {
	in >> obj.a >> obj.b;
	obj.a = obj.a > 0 ? obj.a : 0;
	obj.b = obj.b > 0 ? obj.b : 0;
	return in;
}

// Method to get different objects definition
Algebra* Algebra::getDifferentObjects(const Algebra arr[], int size, int &newSize) const {
	newSize = 0;
	for (int i = 0; i < size; ++i) {
		if (!(*this == arr[i])) {
			++newSize;
		}
	}
	
	if (newSize == 0) {
		newSize = 0;
		return NULL;
	}
	
	Algebra* newArr = new Algebra[newSize];
	int index = 0;
	for (int i = 0; i < size; ++i) {
		if (!(*this == arr[i])) {
			newArr[index++] = arr[i];
		}
	}
	
	return newArr;
}

int main() {
	int n, newSize;
	
	cout << "Enter number of Algebra objects: ";
	cin >> n;
	
	Algebra* arr = new Algebra[n];
	for (int i = 0; i < n; ++i) {
		cout << "Enter values for object " << i + 1 << ": ";
		cin >> arr[i];
	}
	
	Algebra obj; // Create a calling object (default values 0, 0)
	
	Algebra* result = obj.getDifferentObjects(arr, n, newSize);
	
	if (result == NULL) {
		cout << "All objects are equal to calling object.\n";
	} else {
		cout << "Objects different from calling object (new size " << newSize << "):\n";
		for (int i = 0; i < newSize; ++i) {
			cout << "Object " << i + 1 << ": a = " << result[i].getA() << ", b = " << result[i].getB() << endl;
		}
		delete[] result;
	}
	
	delete[] arr;
	
	return 0;
}

