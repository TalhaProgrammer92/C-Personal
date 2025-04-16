#include <iostream>
#include <vector>

using namespace std;

//* Function to sort words in ascending order
void sortWords(vector<string> &words)
{
    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (words[i] > words[j])
            {
                swap(words[i], words[j]);
            }
        }
    }
}

int main()
{
    //! Sorting operations
    vector<string> words = {"banana", "apple", "orange", "grape", "kiwi"};
    sortWords(words);

    //! Display all words
    for (const string &word : words)
        cout << word << " ";

    return 0;
}
