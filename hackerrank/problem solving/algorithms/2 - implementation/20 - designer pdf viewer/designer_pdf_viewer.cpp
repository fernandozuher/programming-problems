// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// C++23

import std;
using namespace std;

constexpr int alphabet_size{ 26 };

array<int, alphabet_size> read_input();
int designer_pdf_viewer(const array<int, alphabet_size>& letters_heights, string_view word);

int main()
{
    array letters_heights{ read_input() };
    string word;
    cin >> word;
    cout << designer_pdf_viewer(letters_heights, word);
    return 0;
}

array<int, alphabet_size> read_input()
{
    array<int, alphabet_size> arr{};
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
int designer_pdf_viewer(const array<int, alphabet_size>& letters_heights, string_view word)
{
    return ranges::max(word | views::transform([&letters_heights](char ch) { return letters_heights[ch - 'a']; })) *
        word.size();
}
