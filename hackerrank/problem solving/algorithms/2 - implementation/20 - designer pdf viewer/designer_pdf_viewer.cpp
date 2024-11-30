// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read();
int area(const vector<int>& letters_heights, string_view word);

int main()
{
    vector<int> letters_heights{read()};
    string word;
    cin >> word;
    cout << area(letters_heights, word);
    return 0;
}

template <class T>
vector<T> read()
{
    string line;
    getline(cin, line);
    istringstream is{line};
    vector<T> array;
    for (T value; is >> value;)
        array.push_back(value);
    return array;
}

int area(const vector<int>& letters_heights, const string_view word)
{
    int max_height{};
    for (const char letter : word) {
        int letter_index{letter - 'a'};
        int letter_height{letters_heights[letter_index]};
        max_height = max(max_height, letter_height);
    }
    return max_height * word.size();
}
