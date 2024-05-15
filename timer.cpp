#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int hour=0, minute=0, second=50;
	
	double before = time(0);
	while (true)
	{
		if (second > 59)
		{
			second = 0;
			minute++;
		}
		if (minute > 59)
		{
			minute = 0;
			hour++;
		}
		if (hour == 24)
			break;
		double after = time(0);
		if (after - before >= 1)
		{
			before = time(0);
			second++;
			system("cls");
			cout << hour << ":" << minute << ":" << second << endl;
		}
	}
	
	return 0;
}
