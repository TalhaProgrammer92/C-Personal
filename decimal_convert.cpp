#include<iostream>

using namespace std;

int main()
{
	// Variables
	int decimal, i = 0;
	int binary[100], octal[100], hexa[100];

	// Get data from user
	cout << "Decimal number>> ";
	cin >> decimal;

	// Binary-Conversion
	for (int decBin = decimal; decBin > 0; decBin /= 2)
	{
		binary[i] = decBin%2; i++;	
	}
	// Binary-Result
	cout << "\nBinary number>> ";
	for (i; i >= 0; i--)
		cout << binary[i];

	// Octal-Conversion
	for (int decOct = decimal; decOct > 0; decOct /= 8)
	{
		octal[i] = decOct%8; i++;
	}
	// Octal-Result
	cout << "\nOctal number>> ";
	for (i; i >= -1; i--)
		cout << octal[i];

	// Hexadecimal-Conversion
	i = 0;
	for (int decHex = decimal; decHex > 0; decHex /= 16)
	{
		hexa[i] = decHex%16; i++;
	}
	// hexadecimal-Result
	cout << "\nHexa-decimal number>> "; int num;
	for (i; i >= 0; i--)
	{
		num = hexa[i];
		// 10-A, 11-B, 12-C, 13-D, 14-E, 15-F
		switch (num)
		{
			case 10:
				cout << 'A'; break;
			case 11:
				cout << 'B'; break;
			case 12:
				cout << 'C'; break;
			case 13:
				cout << 'D'; break;
			case 14:
				cout << 'E'; break;
			case 15:
				cout << 'F'; break;
			default:
				cout << num;
		}
	}
	cout << endl;

	return 0;
}
