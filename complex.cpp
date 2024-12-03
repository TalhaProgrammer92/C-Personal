#include <iostream>

using namespace std;

////////////////////////
// Complex - Class
////////////////////////
class Complex {
public:
	int real, imaginary;
	
	Complex(int r = 0, int i = 0) {
		this->real = r;
		this->imaginary = i;
	}

	////////////////
	// Methods
	////////////////
	void print();
	
	/////////////////////////////
	// Operator Overloading
	/////////////////////////////
	
	Complex operator+(const Complex& obj){
		Complex result;
		result.real = this->real + obj.real;
		result.imaginary = this->imaginary + obj.imaginary;
		return result;
	}
	
	Complex operator-(const Complex& obj){
		Complex result;
		result.real = this->real - obj.real;
		result.imaginary = this->imaginary - obj.imaginary;
		return result;
	}
	
	Complex operator*(const Complex& obj){
		Complex result;
		result.real = this->real * obj.real;
		result.imaginary = this->imaginary * obj.imaginary;
		return result;
	}
	
	Complex operator/(const Complex& obj){
		Complex result;
		result.real = this->real / obj.real;
		result.imaginary = this->imaginary / obj.imaginary;
		return result;
	}
};

////////////////////////
// Main Function
////////////////////////
int main() {
	Complex number1(-8, 9), number2(4, -3);
	Complex add, sub, mul, div;
	
	add = number1 + number2;
	sub = number1 - number2;
	mul = number1 * number2;
	div = number1 / number2;
	
	add.print();
	sub.print();
	mul.print();
	div.print();
}

////////////////////////
// Complex - Methods
////////////////////////

// Print number
void Complex::print() {
	string expression = to_string(this->real);

	(this->imaginary > 0 || this->imaginary == 0) ?
	expression += " + " + to_string(this->imaginary) : expression += " - " + to_string(this->imaginary * -1);
	
	expression += 'i';


	cout << expression << endl;
}
