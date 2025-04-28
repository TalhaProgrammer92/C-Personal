#include <iostream>
#include <vector>

using namespace std;

//* Global Variables
const int shift = 3;

//* Function - Character existance
bool is_char_exist(char &chr, vector<char> &chrs)
{
    for (auto &&c : chrs)
    {
        if (chr == c)
            return true;
    }
    return false;
}

//* Function - Extract words
vector<string> extract_words(string &text)
{
    vector<string> words;
    string word = "";

    for (int i = 0; i < text.length(); i++)
    {
        //! If whitespace
        if (text[i] == ' ' && word.length() > 0)
        {
            words.push_back(word);
            word = "";
            continue;
        }

        //! Add character in word
        word += text[i];
    }

    //! Add last word
    words.push_back(word);

    return words;
}

///////////////////
// Qwerty Cipher //
///////////////////
class QwertyCipher
{
    //* Key Mapping
    vector<vector<char>> qwerty_map;

    //* Get keys array
    vector<char> *getKeys(char key)
    {
        //! Vector of keys (default)
        vector<char> *keys = nullptr;

        //! Iterating throught each pair
        for (int i = 0; i < qwerty_map.size(); i++)
        {
            if (is_char_exist(key, qwerty_map[i]))
                keys = &qwerty_map[i];
        }

        return keys;
    }

    //* Get index of specific key-value
    int getKeyIndex(char &chr, vector<char> &values)
    {
        for (int i = 0; i < values[i]; i++)
            if (values[i] == chr)
                return i;
        return -1;
    }

    //* Parse
    void parse(char &chr, bool mode /* 1 - Encode | 0 - Decode */)
    {
        if (isalnum(chr) || ispunct(chr) /* Access only alpha-numeric-punctuation keys */)
        {
            //! Necessary variables
            vector<char> keys = *getKeys(chr);
            int pointer = getKeyIndex(chr, keys);

            //! Shifting key
            for (int i = 0; i < abs(shift); i++)
            {
                //* Encoding
                if (mode)
                {
                    (pointer + 1 < keys.size()) ? pointer++ : pointer = 0;
                }
                //* Decoding
                else
                {
                    (pointer - 1 >= 0) ? pointer-- : pointer = keys.size() - 1;
                }
            }

            //! Shift the character key
            chr = keys[pointer];
        }
    }

public:
    //* Constructor
    QwertyCipher()
    {
        //! Values (Keyboard keys)
        qwerty_map = {
            {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+'},
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '|'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?'}};
    }

    //* Prase the input
    void parse_text(string &text, bool mode = true /* 1 - Encode | 0 - Decode */)
    {
        for (int i = 0; i < text.length(); i++)
            parse(text[i], mode);
    }
};

/////////////////
// EVOD Cipher //
/////////////////
class EvodCipher
{
    vector<string> words;
    string *text;

public:
    //* Constructor
    EvodCipher(string &text)
    {
        words = extract_words(text);
        this->text = &text;
    }

    //* Parse words
    void parse(bool mode = true /* 1 - Encode | 0 - Decode */)
    {
        if (this->words.size() > 1)
        {
            //! Variables
            //* Store encoded/decoded text
            string _text = "";
            //* Repositioned words
            vector<string> _words;
            //* Size of the vector of words
            int size = this->words.size();

            //* Encode
            if (mode)
            {
                //! Iterate through each word - Even index
                for (int i = 0; i < size; i += 2)
                    _words.push_back(this->words[i]);

                //! Iterate through each word - Odd index
                for (int i = 1; i < size; i += 2)
                    _words.push_back(this->words[i]);
            }

            //* Decoded
            else
            {
                //! Necessary variables
                int even_pointer = 0, odd_pointer = (size % 2) ? size / 2 + 1 : size / 2, even_limit = odd_pointer, odd_limit = size;
                /*

                0 1 2 3 4 -- 5 (odd) => 0 2 4 1 3 (even: 0, odd: 3 = size / 2 + 1)
                0 1 2 3 -- 4 (even) => 0 2 1 3 (even: 0, odd: 2 = size / 2)
                0 1 2 -- 3 (odd) => 0 2 1 (even: 0, odd: 2 = size / 2 + 1)
                0 1 -- 2 (even) => 0 1 (even: 0, odd 1 = size / 2)
                0 -- 1 (odd) => 0 (even: 0, odd: null)

                */

                //! Reposition words to actaul position
                while (even_pointer < even_limit || odd_pointer < odd_limit)
                {
                    if (even_pointer < even_limit)
                        _words.push_back(this->words[even_pointer++]);
                    if (odd_pointer < odd_limit)
                        _words.push_back(this->words[odd_pointer++]);
                }
            }

            //! Join with ' '
            for (int i = 0; i < size; i++)
            {
                _text += _words[i];

                if (i < size - 1)
                    _text += ' ';
            }

            //! Assignment
            *text = _text;
        }
    }
};

////////////////
// Algorithms //
////////////////
class Layers
{
public:
    //* Ceaser Cipher - Layer 1
    static void ceaser_cipher(string &text, bool mode = true)
    {
        for (int i = 0; i < text.length(); i++)
        {
            if (isalnum(text[i]))
                text[i] += (mode) ? shift : -shift;
        }
    }

    //* Qwerty Cipher - Layer 2
    static void qwerty_cipher(string &text, bool mode = true)
    {
        QwertyCipher().parse_text(text, mode);
    }

    //* Evod Cipher - Layer 3
    static void evod_cipher(string &text, bool mode = true)
    {
        EvodCipher(text).parse(mode);
    }
};

//* Perform encoding/decoding
void cipher(string &text, bool mode = true)
{
    if (mode)
    {
        cout << "\nEncoded: ";

        Layers::ceaser_cipher(text); //! Layer 1
        Layers::qwerty_cipher(text); //! Layer 2
        Layers::evod_cipher(text);   //! Layer 3
    }
    else
    {
        cout << "\nDecoded: ";

        Layers::evod_cipher(text, mode);   //! Layer 3
        Layers::qwerty_cipher(text, mode); //! Layer 2
        Layers::ceaser_cipher(text, mode); //! Layer 1
    }
}

int main()
{
    string message = "Hello! Welcome to C.H.A.O.S Cipher";

    //* Encoding
    cipher(message);

    cout << message << endl;

    //* Decoding
    cipher(message, 0);

    cout << message << endl;

    return 0;
}

/*

* OUTPUT

Encoded: "l]]u$ tu JAg'lp Vl]ju\l JX"XHXUXM

Decoded: Hello! Welcome to C.H.A.O.S Cipher

*/
