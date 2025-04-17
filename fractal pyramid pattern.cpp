#include <iostream>

using namespace std;

int main()
{
    //! Number of layers
    int n = 4;

    //! Check if the number of layers is valid
    if (n >= 1 && n <= 6)
    {
        //! Calculations
        int
            height = 2 * n - 1,
            width = 2 * n - 1,
            whitespaces = (height - 1) + (n * 2) - 2,
            stars = 1;

        //! Generate upper cone
        for (int i = 0; i < height; i++)
        {
            //! Whitespaces
            for (int j = 0; j < whitespaces; j++)
                cout << ' ';

            //! Stars
            for (int j = 0; j < stars; j++)
            {
                //! Top hollow part
                if (i < height - 1)
                    (j == 0 || j == stars - 1) ? cout << '*' : cout << ' ';

                //! Bottom part
                else
                    (j % 2 == 0) ? cout << '*' : cout << ' ';
            }

            //! New line
            cout << endl;

            //! Update varaibles
            stars += 2;
            whitespaces--;
        }

        //! Generate Layers
        for (int i = 0; i < n / 2 + 1; i++)
        {
            //! Cycle
            for (int j = 0; j < 2; j++)
            {
                //! White spaces
                for (int k = 0; k < whitespaces; k++)
                    cout << ' ';

                //! Stars
                for (int k = 0; k < stars; k++)
                {
                    //! Hollow part
                    if (j == 0)
                        (k == 0 || k == stars - 1) ? cout << '*' : cout << ' ';

                    //! Filled part
                    else
                        (k % 2 == 0) ? cout << '*' : cout << ' ';
                }

                //! New line
                cout << endl;

                //! Update
                stars += 2;
                whitespaces--;
            }
        }
    }

    return 0;
}

/*
[Output n = 3]

        *
       * *
      *   *
     *     *
    * * * * *
   *         *
  * * * * * * *
 *             *
* * * * * * * * *

[Output n = 4]

            *
           * *
          *   *
         *     *
        *       *
       *         *
      * * * * * * *
     *             *
    * * * * * * * * *
   *                 *
  * * * * * * * * * * *
 *                     *
* * * * * * * * * * * * *

*/
