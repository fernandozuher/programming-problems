// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true
// C++23

import std;
using namespace std;

long long count_in_repeated_string(string_view str, char letter, long long n_chars);

int main()
{
    string str;
    long long n_chars;
    cin >> str >> n_chars;

    constexpr char letter{ 'a' };
    println("{}", count_in_repeated_string(str, letter, n_chars));

    return 0;
}

// n: length of str
// T: O(n)
// S: O(1) extra space
long long count_in_repeated_string(string_view str, char letter, long long n_chars)
{
    auto [full_repeats, n_substr] { div(n_chars, str.length()) };
    string_view substr{ str.begin(), str.begin() + n_substr };

    auto count{ ranges::count(str, letter) };
    count *= full_repeats;
    return count + ranges::count(substr, letter);
}
