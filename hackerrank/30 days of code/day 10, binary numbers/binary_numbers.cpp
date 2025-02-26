// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int max_consecutive_ones_from(const string_view& binary);
int size_of_next_range_of_bits_1(const string_view& binary, int begin_index);
int find_next_after_last_index_of_consecutive_1s(const string_view& binary, int begin_index);

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
        if (binary[i] == '1') {
            int n_bits{size_of_next_range_of_bits_1(binary, i)};
            max_n_bits = max(n_bits, max_n_bits);
            i += n_bits;
        }
    }
    return max_n_bits;
}

int size_of_next_range_of_bits_1(const string_view& binary, const int begin_index)
{
    int next_after_last_index{find_next_after_last_index_of_consecutive_1s(binary, begin_index)};
    return next_after_last_index - begin_index;
}

int find_next_after_last_index_of_consecutive_1s(const string_view& binary, const int begin_index)
{
    auto it{find(binary.begin() + begin_index, binary.end(), '0')};
    if (it == binary.end())
        return static_cast<int>(binary.size());

    int next_after_last_index{static_cast<int>(distance(binary.begin(), it))};
    return next_after_last_index;
}
