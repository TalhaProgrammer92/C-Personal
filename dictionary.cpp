#include <iostream>

using namespace std;

// 16-bit dictionary
class Dictionary
{
private:
    int Key[16];
    int Value[16];
    int Index = 0;

    int GetIndex(int number)
    {
        for (int i = 0; i < 16; i++)
        {
            if (this->Key[i] == number || this->Value[i] == number)
                return i;
        }
        return -1;
    }

public:
    void SetData(int key, int value)
    {
        if (this->Index < 16)
        {
            *this->Key = key;
            *this->Value = value;
            this->Index++;
        }
        cout << "Maximum range is 16!" << endl;
    }
    int GetValue(int key)
    {
        int index = GetIndex(key);
        if (index != -1)
            return Value[index];
        return 0;
    }
    int GetKey(int value)
    {
        int index = GetIndex(value);
        if (index != -1)
            return Value[index];
        return 0;
    }
};

int main()
{
    cout << "Making Object!" << endl;
    Dictionary MyDict;

    cout << "Filling Object!" << endl;
    MyDict.SetData(0, -1);
    MyDict.SetData(1, -2);
    MyDict.SetData(2, -3);

    cout << "Showing Object!" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Key:    " << MyDict.GetKey((i + 1) * -1) << endl;
        cout << "Value:  " << MyDict.GetValue(i) << endl;
    }

    return 0;
}