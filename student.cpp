#include <iostream>
#include <vector>

using namespace std;

int Id = 0;

class Student{
protected:
	int studentId;
	string studentName;
	vector<string> courses;
public:
	Student(string studentName);
	void addCourse(string courseName);
	void displayStudentDetails();
};

class GraduateStudent : public Student{
public:
	string thesisTitle;
	GraduateStudent(string name, string thesis);
	void displayStudentDetails();
};

int main()
{
	Student std1("Ahmad Aslam");
	std1.addCourse("Science");
	std1.addCourse("Math");
	std1.addCourse("English");
	std1.addCourse("History");
	
	GraduateStudent std2("Talha Ahmad", "Problem Solving");
	std2.addCourse("Python");
	std2.addCourse("Data Structure and Algorithms");
	std2.addCourse("System Design");
	
	std1.displayStudentDetails();
	std2.displayStudentDetails();
}

Student::Student(string studentName)
{
	this->studentName = studentName;
	studentId = ++Id;
}

void Student::addCourse(string courseName)
{
	courses.push_back(courseName);
}

void Student::displayStudentDetails()
{
	cout << "\nStudent Id:\t" << studentId << endl
		 << "Student Name:\t" << studentName << endl
		 << "Courses Enrolled:" << endl;
	
	for(unsigned int i=0;i<courses.size();i++)
		cout << i + 1 << ". " << courses.at(i) << endl;
}

GraduateStudent::GraduateStudent(string name, string thesis) : Student(name)
{
	thesisTitle = thesis;
}

void GraduateStudent::displayStudentDetails()
{
	Student::displayStudentDetails();
	cout << "Thesis Title:\t" << thesisTitle << endl;
}
