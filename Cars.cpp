#include <iostream>
#include <vector>

using namespace std;


//////////////////

// Car

//////////////////
class Car {
private:
	string model, color, type;
	int price;
	bool sold_status;
public:
	// Constructors
	Car(){
		
	}
	
	Car(string model, string color, string type, int price) {
		this->model = model;
		this->color = color;
		this->type = type;
		this->price = price;
		this->sold_status = false;
	}
	
	// Display details
	void details() {
		cout << "Model:\t" << model << '\n'
		<< "Color:\t" << color << '\n'
		<< "Type:\t" << type << '\n'
		<< "Price:\t$" << price << '\n'
		<< "Sold:\t" << sold_status << "\n\n";
	}
	
	// Sold status
	bool isSold() {
		return sold_status;
	}
	
	// Sell the car
	void sell() {
		sold_status = true;
	}
};


//////////////////

// Stock

//////////////////
class Stock {
private:
	vector<Car> stock;
public:
	// Add stock
	void add(Car car) {
		stock.push_back(car);
	}
	
	// Get stock
	Car sellCar(int Id) {
		Car car;
		
		if (stock.at(Id).isSold()) {
			car = Car();
			car.sell();
		} else {
			car = stock.at(Id);
			stock.at(Id).sell();
		}
		
		return car; // Semicolon added here
	}
	
	// Check number of cars in the stock
	unsigned int numberOfCarsLeft() {
		unsigned int count = 0;
		
		for (unsigned int i = 0; i < stock.size(); i++)
			if (!stock.at(i).isSold())
				count++;
		
		return count;
	}
	
	// Print details
	void details() {
		for (unsigned int i = 0; i < stock.size(); i++) {
			cout << "Id:\t" << i << '\n';
			stock.at(i).details();
		}
	}
};


//////////////////

// Main

//////////////////
int main() {
	Stock my_stock;
	
	my_stock.add(Car("Super", "Red", "Sports", 200000));
	my_stock.add(Car("X2", "White", "Seden", 10000));
	my_stock.sellCar(0);
	
	my_stock.details();
	
	return 0;
}
