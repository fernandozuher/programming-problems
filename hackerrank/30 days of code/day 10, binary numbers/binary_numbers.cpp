// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <algorithm>
#include <bitset>
#include <iostream>
#include <tuple>

using namespace std;

int max_consecutive_ones_from(const string_view& binary);
tuple<int, int> find_range_bits_1(const string_view& binary, int i);
int find_index(const string_view& binary, int i, char data);

int main()
{
    int n;
    cin >> n;
    auto binary{bitset<32>(n).to_string()};
    cout << max_consecutive_ones_from(binary);
    return 0;
}

int max_consecutive_ones_from(const string_view& binary)
{
    int max_n_bits{};
    for (int i{}; i < binary.size(); ++i) {
        auto [first, next_after_last]{find_range_bits_1(binary, i)};
        int n_bits{next_after_last - first};
        max_n_bits = max(n_bits, max_n_bits);
        i = next_after_last;
    }
    return max_n_bits;
}

tuple<int, int> find_range_bits_1(const string_view& binary, const int i)
{
    return {find_index(binary, i, '1'), find_index(binary, i, '0')};
}

int find_index(const string_view& binary, const int i, const char data)
{
    auto it{find(binary.begin() + i, binary.end(), data)};
    return static_cast<int>(distance(binary.begin(), it));
}
