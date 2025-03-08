// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

string int_to_binary(int n);
int find_size_widest_range_bits_1_from(const string_view& binary);
int find_size_next_range_bits_1_from(const string_view& binary);

int main()
{
    int n;
    cin >> n;
    string binary{int_to_binary(n)};
    cout << find_size_widest_range_bits_1_from(binary);
    return 0;
}

string int_to_binary(const int n)
{
    return bitset<32>(n).to_string();
}

int find_size_widest_range_bits_1_from(const string_view& binary)
{
    int size_widest_range{};
    for (int i{}; i < binary.size(); ++i)
        if (binary[i] == '1') {
            string_view binary_from_i = binary.substr(i);
            int size_range = find_size_next_range_bits_1_from(binary_from_i);
            size_widest_range = max(size_range, size_widest_range);
            i += size_range;
        }
    return size_widest_range;
}

int find_size_next_range_bits_1_from(const string_view& binary)
{
    if (auto it{ranges::find(binary, '0')}; it != binary.end())
        return distance(binary.begin(), it);
    return binary.size();
}
