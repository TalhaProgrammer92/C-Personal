#include <iostream>
#include <vector>

using namespace std;

class Dict{
    private:
        vector<pair<string, string>> data;
        
    public:
    
        // Insert a key-value pair into the dictionary
        void insert(string key, string value) {
            data.push_back(make_pair(key, value));
        }
        
        // Search for a value given a key
        string search(string key) {
            for (auto &entry : data) {
                if (entry.first == key) {
                    return entry.second;
                }
            }
            return "";
        }
};

int main()
{
    Dict dictionary;

    dictionary.insert("apple", "fruit");
    dictionary.insert("banana", "fruit");
    dictionary.insert("orange", "fruit");
    dictionary.insert("carrot", "vegetable");
    dictionary.insert("potato", "vegetable");
    dictionary.insert("banana", "fruit");

    cout << "Search for 'apple': " << dictionary.search("apple") << endl;
    cout << "Search for 'potato': " << dictionary.search("potato") << endl;
    cout << "Search for 'tomato': " << dictionary.search("tomato") << endl;
}
