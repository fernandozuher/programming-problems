// It checks if number has only one bit set

#include <bitset>
#include <iostream>
#include <ranges>

using namespace std;

bool has_only_one_bit_set(int n);

int main()
{
    constexpr auto n_bits{sizeof(int) * 8};
    for (constexpr auto n{101}; const int i : views::iota(0, n))
        cout << i << ", " << bitset<n_bits>(i) << ", " << (has_only_one_bit_set(i) ? '1' : ' ') << '\n';
    return 0;
}

bool has_only_one_bit_set(const int n)
{
    return (n & (n - 1)) == 0;
}
