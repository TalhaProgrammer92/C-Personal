#include <iostream>

using namespace std;


////////////////////
// Set - Class
////////////////////
class Set{
public:
	// Attributes
	int *array;
	int size;
	
	// Constructor
	Set(int size);
	
	// Setter
	void setValue();
	
	// Display the set
	void display();
	
	// Operations
	void set_union(Set set1, Set set2);
	void set_difference(Set set1, Set set2);
};


////////////////////////
// Main - Function
////////////////////////
int main()
{
	Set A(4), B(3);
	
	// Set values
	A.setValue();
	B.setValue();
	
	// Display A & B
	cout << "Set A:\t\t";
	A.display();
	cout << "Set B:\t\t";
	B.display();
	
	// Display and calculate union
	cout << "Union:\t\t";
	A.set_union(A, B);
	
	// Display and calculate difference
	cout << "Difference:\t";
	A.set_difference(A, B);
}


//////////////////////////////
// Set - Class (Methods)
//////////////////////////////

Set::Set(int size)
{
	this->size = size;
	array = new int[size];
}

void Set::setValue()
{
	cout << "Enter emlements of the set:" << endl;
	for(int i=0;i<size;i++){
		cout << "Element " << i + 1 << ">> ";
		cin >> array[i];
	}
}

void Set::display()
{
	cout << '{';
	for(int i=0;i<size;i++){
		cout << to_string(array[i]) + ", ";
	}
	cout << "\b\b}" << endl;
}

void Set::set_union(Set set1, Set set2)
{
	Set union_set(set1.size + set2.size);
	int i, j, k = 0;
	
	// Copy the elements from 1st set
	for(i=0;i<set1.size;i++)
		union_set.array[k++] = set1.array[i];
	
	// Copy the elements from 2nd set
	for(i=0;i<set2.size;i++){
		bool duplicate = false;
		
		// Checking for any duplicate value
		for(j = 0; j < set1.size; j++){
			if (set2.array[i] == set1.array[j]){
				duplicate = true;
				break;
			}
		}
		
		// Add the value
		if (!duplicate)
			union_set.array[k++] = set2.array[i];
	}
	
	// Resize
	union_set.size = k;
	
	// Display the result
	union_set.display();
}

void Set::set_difference(Set set1, Set set2)
{
	Set diff_set(set1.size);
	int i, j, k = 0;
	
	// Calculating difference b/w the two given sets
	for(i=0;i<set1.size;i++){
		bool present = false;
		
		// Check if the value is present
		for(j = 0; j<set2.size; j++){
			if (set1.array[i] == set2.array[j]){
				present = true;
				break;
			}
		}
		
		// Add the value
		if (!present)
			diff_set.array[k++] = set1.array[i];
	}
	
	// Resize
	diff_set.size = k;
	
	// Display the result
	diff_set.display();
}

