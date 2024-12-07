#include <iostream>
#include <cmath>

using namespace std;

////////////////////////
// Complex - Class
////////////////////////
class Complex {
public:
	double real, imaginary;
	
	Complex(double r = 0, double i = 0) {
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
		/*
		(a + bi) * (c + di) = ac + adi + bci + bdi2 = ac - bd + (ad + bc)i
		*/
		Complex result;
		result.real = this->real * obj.real - this->imaginary * obj.imaginary;
		result.imaginary = this->real * obj.imaginary + this->imaginary * obj.real;
		return result;
	}
	
	Complex operator/(const Complex& obj){
		/*
		(a + bi) / (c + di) = [(a + bi) / (c + di)] * [(c - di) / (c - di)] = [(a + bi) * (c - di)] / [(c + di)(c - di)]
		= (ac - adi + bci - bdi2) / [c2 - (di)2] = [ac + db + (bc - ad)i] / (c2 + d2) = [(ac + bd) / (c2 + d2)] + [(bc - ad) / (c2 + d2)]i   
		*/
		Complex result;
		result.real = (this->real * obj.real + this->imaginary * obj.imaginary) / (pow(obj.real, 2) + pow(obj.imaginary, 2));
		result.imaginary = (this->imaginary * obj.real - this->real * obj.imaginary) / (pow(obj.real, 2) + pow(obj.imaginary, 2));
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
