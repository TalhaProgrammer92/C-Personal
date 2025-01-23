#include <iostream>
#include <cmath>

using namespace std;

class Shape {
	virtual void calculateArea() = 0;	// Pure virtual function
};

class Circle : public Shape {
public:
	double radius;
	void calculateArea() override;
};

class Rectangle : public Shape {
public:
	double length, width;
	void calculateArea() override;
};

class Triangle : public Shape {
public:
	double base, height;
	void calculateArea() override;
};

int main() {
	Circle circle;
	circle.radius = 12.23;
	
	Rectangle rectangle;
	rectangle.length = 4.5;
	rectangle.width = 7.86;
	
	Triangle triangle;
	triangle.base = 6.12;
	triangle.height = 12.12465;
	
	circle.calculateArea();
	rectangle.calculateArea();
	triangle.calculateArea();
}

void Circle::calculateArea()
{
	double area;
	
	area = M_PI * pow(radius, 2);
	
	cout << "Area of the circle is " << area << endl;
}

void Rectangle::calculateArea()
{
	double area;
	
	area = width * length;
	
	cout << "Area of the rectangle is " << area << endl;
}

void Triangle::calculateArea()
{
	double area;
	
	area = (base * height) / 2.0;
	
	cout << "Area of the triangle is " << area << endl;
}

