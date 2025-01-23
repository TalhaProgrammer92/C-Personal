#include <iostream>

using namespace std;

int Id = 0;

class Employee{
protected:
	int employeeId;
	string employeeName;
	double employeeSalary;
public:
	Employee(string name, double salary);
	double calculateNetSalary();
	void displayEmployeeDetails();
};

class Manager : public Employee{
private:
	string department;
public:
	Manager(string name, double salary, string department);
	double calculateNetSalary();
	void displayEmployeeDetails();
};

int main()
{
	Employee employee("Talha Ahmad", 80000);
	employee.displayEmployeeDetails();
	
	Manager manager("Abdul Rehman", 120000, "Design");
	manager.displayEmployeeDetails();
}

Employee::Employee(string name, double salary)
{
	employeeName = name;
	employeeSalary = salary;
	employeeId = ++Id;
}

double Employee::calculateNetSalary()
{
	return employeeSalary - ((10 * employeeSalary) / 100);
}

void Employee::displayEmployeeDetails()
{
	cout << "Employee Id:\t\t" << employeeId << endl
		 << "Employee Name:\t\t" << employeeName << endl
		 << "Employee Net Salary:\t" << calculateNetSalary() << endl;
}

Manager::Manager(string name, double salary, string department) : Employee(name, salary)
{
	this->department = department;
}

double Manager::calculateNetSalary()
{
	return employeeSalary + ((10 * employeeSalary) / 100);
}

void Manager::displayEmployeeDetails()
{
	cout << "Employee Id:\t\t" << employeeId << endl
		 << "Department:\t\t" << department << endl
		 << "Employee Name:\t\t" << employeeName << endl
		 << "Employee Net Salary:\t" << calculateNetSalary() << endl;
}

