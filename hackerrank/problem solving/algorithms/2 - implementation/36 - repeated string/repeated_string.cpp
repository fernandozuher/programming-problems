// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

#include <algorithm>;
#include <iostream>;
#include <string_view>;

using namespace std;

long count_in_repeated_string(const string_view& input_string, char letter, long n_characters);

int main()
{
    string input_string;
    long n_characters;
    cin >> input_string >> n_characters;

    constexpr char letter{'a'};
    cout << count_in_repeated_string(input_string, letter, n_characters) << '\n';

    return 0;
}

long count_in_repeated_string(const string_view& input_string, char letter, long n_characters)
{
    auto [full_repeats, n_substring]{div(n_characters, input_string.length())};
    string_view substring{input_string.begin(), input_string.begin() + n_substring};

    long quantity{ranges::count(input_string, letter)};
    quantity *= full_repeats;
    return quantity + ranges::count(substring, letter);
}
