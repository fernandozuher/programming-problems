// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <string_view>

using namespace std;

long count_in_repeated_string(const string_view input_string, const char letter, const long n_characteres);

int main()
{
    string input_string;
    cin >> input_string;
    long n_characteres;
    cin >> n_characteres;

    constexpr char letter {'a'};
    cout << count_in_repeated_string(input_string, letter, n_characteres) << '\n';

    return 0;
}

    long count_in_repeated_string(const string_view input_string, const char letter, const long n_characteres)
    {
        auto [repeated_entire_string, n_substring] {div(n_characteres, input_string.length())};
        string_view substring {input_string.begin(), input_string.begin() + n_substring};

        long quantity {ranges::count(input_string, letter)};
        quantity *= repeated_entire_string;
        quantity += ranges::count(substring, letter);

        return quantity;
    }
