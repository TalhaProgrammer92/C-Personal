#include <iostream>

using namespace std;

template <class Type>
class Vector
{
public:
    // Data
    Type *array;
    int size;

    // Constructor
    Vector(int size) : size(size)
    {
        array = new Type[size];
    }

    // dot product
    Type dotProduct(Vector<Type> &other)
    {
        if (size != other.size)
            throw "Vectors must have the same size.";

        Type result = 0;
        for (int i = 0; i < size; i++)
            result += array[i] * other.array[i];

        return result;
    }
};

int main()
{
    // ! For 'int' datatype
    Vector<int> v_int1(3);
    Vector<int> v_int2(3);

    // Set values
    v_int1.array[0] = 1;
    v_int1.array[1] = 2;
    v_int1.array[2] = 3;

    v_int2.array[0] = 4;
    v_int2.array[1] = 5;
    v_int2.array[2] = 6;

    // Dot product
    try {
        cout << "Dot product (int): " << v_int1.dotProduct(v_int2) << endl;
    } catch (const char* error) {
        cerr << error << endl;
    }

    // ! For 'float' datatype
    Vector<float> v_float1(3);
    Vector<float> v_float2(3);

    // Set values
    v_float1.array[0] = 1.5;
    v_float1.array[1] = 2.5;
    v_float1.array[2] = 3.5;

    v_float2.array[0] = 4.5;
    v_float2.array[1] = 5.5;
    v_float2.array[2] = 6.5;

    // Dot product
    try
    {
        cout << "Dot product (float): " << v_float1.dotProduct(v_float2) << endl;
    }
    catch (const char *error)
    {
        cerr << error << endl;
    }
}
