#include <iostream>

using namespace std;

int main()
{
  //! Variables
  int
    n = 5,    //* You can change it
    count = n,
    whitespaces = 0;
  
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
    count += (i < n - 1) ? -1 : 1;
    whitespaces += (i < n - 1) ? 2 : -2;
  }

  return 0;
}

/*

n = 5

Row 0: 5 4 3 2 1 2 3 4 5
Row 1:   4 3 2 1 2 3 4
Row 2:     3 2 1 2 3
Row 3:       2 1 2
Row 4:         1
Row 5:       2 1 2
Row 6:     3 2 1 2 3
Row 7:   4 3 2 1 2 3 4
Row 8: 5 4 3 2 1 2 3 4 5

*/