// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C++23

import std;
using namespace std;

long long count_in_repeated_string(string_view input_string, char letter, long long n_characters);

int main()
{
    string input_string;
    long long n_characters;
    cin >> input_string >> n_characters;

    constexpr char letter{ 'a' };
    println("{}", count_in_repeated_string(input_string, letter, n_characters));

    return 0;
}

// n: length of string
// T: O(n)
// S: O(1) extra space
long long count_in_repeated_string(string_view input_string, char letter, long long n_characters)
{
    auto [full_repeats, n_substring] {div(n_characters, input_string.length())};
    string_view substring{ input_string.begin(), input_string.begin() + n_substring };

    auto count{ ranges::count(input_string, letter) };
    count *= full_repeats;
    return count + ranges::count(substring, letter);
}
