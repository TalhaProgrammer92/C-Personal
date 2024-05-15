#include<iostream>
using namespace std;

// Array sorting program
int main()
{
    // variables
    int temp, array[8] = {6, 1, 3, 2, 5, 7, 8, 4};
    // show the array
    cout << "Unsorted:" << endl;
    for (int i=0; i<8; i++)
        cout << array[i] << "\t";
    cout << endl;
    // sorting 0-9
    for (int i = 0; i < 8; i++)
    {
        for (int j=i+1; j < 8; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    // result
    cout << "Sorted 0-9:" << endl;
    for (int i=0; i<8; i++)
        cout << array[i] << "\t";
    cout << endl;
    // sorting 9-0
    for (int i = 0; i < 8; i++)
    {
        for (int j=i+1; j < 8; j++)
        {
            if (array[j] > array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    cout << "Sorted 9-0:" << endl;
    for (int i=0; i<8; i++)
        cout << array[i] << "\t";
    cout << endl;
    return 0;
}