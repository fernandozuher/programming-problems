// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int designer_pdf_viewer(const vector<int>& letters_heights, const string_view& word);

int main()
{
    constexpr int n{26};
    vector letters_heights{read_numbers(n)};
    string word;
    cin >> word;
    cout << designer_pdf_viewer(letters_heights, word);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int designer_pdf_viewer(const vector<int>& letters_heights, const string_view& word)
{
    int max_height{};
    for (auto letter : word)
        max_height = max(max_height, letters_heights[letter - 'a']);
    return max_height * word.size();
}
