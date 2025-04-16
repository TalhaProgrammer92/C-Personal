/*

[INPUT]
This is a test.
This test is only a TEST.

[OUTPUT]
Total unique words: 5

Most frequent word: test (3 times)

Word Frequencies:
test: 3
this: 2
is: 2
a: 2
only: 1

*/

#include <iostream>
#include <vector>

using namespace std;

////////////////
// Word class //
////////////////
class Word
{
private:
    //* Attributes
    string word;
    int frequency = 0;

public:
    //* Constructors
    Word() {}
    Word(string w) : word(w) {}

    //* Getters
    string getWord() { return word; }
    int getFrequency() const { return frequency; }

    //* Increment frequency
    void incrementFrequency() { frequency++; }

    //* Overloaded operators.

    //! This would be case-insensitive.
    bool operator==(const Word &other) const
    {
        //! Check length first.
        if (word.length() == other.word.length())
        {
            //! Check if both words are exactly the same.
            if (word == other.word)
            {
                return true;
            }

            else
            {
                //! Check if both words are the same ignoring case.
                for (int i = 0; i < word.length(); i++)
                    if (abs(word[i] - other.word[i]) != 32)
                        return false;

                return true;
            }
        }

        return false;
    }

    //! Display word with <<
    friend ostream &operator<<(ostream &os, const Word &w)
    {
        os << w.word << " (" << w.frequency << " times)";
        return os;
    }

    //* Display method
    void display()
    {
        cout << word << ": " << frequency << endl;
    }
};

//* Function to check if word already exist. If yes then return it's index at words vector
int checkWordExists(vector<Word> &words, Word word)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == word)
        {
            return i;
        }
    }
    return -1;
}

//* Function to parse text and generate words
vector<Word> parseText(string text)
{
    //! Create a vector of words
    vector<Word> words;
    string word = "";

    //! Loop through each character in the text
    for (char c : text)
    {
        //! Check if character is alphanumeric or a hyphen
        if (isalnum(c))
        {
            word += c;
        }
        else if (word != "")
        {
            words.push_back(Word(word));
            word = "";
        }
    }

    //! Check if there is a word left at the end of the text
    if (word != "")
    {
        words.push_back(Word(word));
    }

    return words;
}

//* Get most frequent word
Word getMostFrequentWord(const vector<Word> &words)
{
    Word mostFrequentWord = words[0];

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i].getFrequency() > mostFrequentWord.getFrequency())
        {
            mostFrequentWord = words[i];
        }
    }

    return mostFrequentWord;
}

////////////////////
// Sentence class //
////////////////////
class Sentence
{
private:
    //* Attributes
    vector<Word> words;

public:
    //* Constructors
    Sentence() {}

    //* Add word to sentence
    void addWord(Word word)
    {
        //! Check if word already exists in the vector
        int index = checkWordExists(words, word);

        //! If it exists, increment frequency. If not, add it to the vector
        if (index != -1)
        {
            words[index].incrementFrequency();
        }
        else
        {
            words.push_back(word);
            words[words.size() - 1].incrementFrequency();
        }
    }

    //* Get words in sentence
    vector<Word> getWords() { return words; }
};

int main()
{
    //! Take input
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    //! Create objects
    Sentence sentence;
    vector<Word> words = parseText(text);

    //! Add words to sentence
    for (Word word : words)
        sentence.addWord(word);

    //! Get words from sentence
    words = sentence.getWords();

    //! Display total words
    cout << "Total unique words: " << words.size() << endl;

    //! Display most frequent word
    Word mostFrequentWord = getMostFrequentWord(words);
    cout << "\nMost frequent word: " << mostFrequentWord << endl;

    //! Display all words
    cout << "\nWord Frequencies:" << endl;
    for (Word word : words)
        word.display();

    return 0;
}
