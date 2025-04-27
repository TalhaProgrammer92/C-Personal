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
};

//* Perform encoding/decoding
void cipher(string &text, bool mode = true)
{
    if (mode)
    {
        cout << "\nEncoded: ";
        
        Layers::ceaser_cipher(text);    //! Layer 1
        Layers::qwerty_cipher(text);    //! Layer 2
    }
    else
    {
        cout << "\nDecoded: ";

        Layers::qwerty_cipher(text, mode);  //! Layer 2
        Layers::ceaser_cipher(text, mode);  //! Layer 1
    }
}

int main()
{
    // string message = "Hello! Welcome to C.H.A.O.S Cipher";
    string message = "\n#include<iostream>\nint main()\n{\n\tstd::cout << \"Hello, World!\" std::endl;\n}";

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

Encoded: 
^Arj]bklzAumtplh\x
Art \hAr+
q
        mtkssjubt zz d"l]]uZ Vup]k$d mtksslrk]S
w

Decoded: 
#include<iostream>
int main()
{
        std::cout << "Hello, World!" std::endl;
}

*/
