#include <iostream>

using namespace std;

int main()
{
  //! Variables
  int
    n = 5,    //* You can change it
    count = 1,
    whitespaces = (n - 1) * 2;
  
  //! Draw Pattern
  for (int i = 0; i < n * 2 - 1; i++)
  {
    //! Whitespaces
    for (int j = 0; j < whitespaces; j++)
      cout << ' ';
    
    //! Numbers
    int num = count, offset = -1;
    for (int j = 0; j < count * 2 - 1; j++)
    {
      cout << num << ' ';

      if (num == 1) offset = 1;

      num += offset;
    }
    
    //! New Line
    cout << endl;

    //! Update Variables
    count += (i < n - 1) ? 1 : -1;
    whitespaces += (i < n - 1) ? -2 : 2;
  }

  return 0;
}

/*

n = 5;

        1         | i = 0
      2 1 2       | i = 1
    3 2 1 2 3     | i = 2
  4 3 2 1 2 3 4   | i = 3
5 4 3 2 1 2 3 4 5 | i = 4
  4 3 2 1 2 3 4   | i = 5
    3 2 1 2 3     | i = 6
      2 1 2       | i = 7
        1         | i = 8

*/