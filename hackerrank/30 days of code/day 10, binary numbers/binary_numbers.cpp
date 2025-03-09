// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true
// From C++20 onwards

#include <algorithm>
#include <bitset>
#include <iostream>
#include <ranges>

using namespace std;

size_t find_max_length_of_ones(const string_view& binary);

int main()
{
    int n;
    cin >> n;
    string binary{bitset<32>(n).to_string()};
    cout << find_max_length_of_ones(binary);
    return 0;
}

size_t find_max_length_of_ones(const string_view& binary)
{
    return ranges::max(binary | views::split('0') | views::transform([](const auto& segment){return segment.size();}));
}
