// From C++23

#include <bitset>
#include <iomanip>
#include <iostream>
#include <print>
#include <ranges>

using namespace std;

pair<int, int> initialize_bit_masks();
int set_bit(int n, int i);
int swap_bits(int n, const pair<int, int>& masks);

int main()
{
    println("n");
    println("n swapped bits");
    cout << left;
    const auto masks{initialize_bit_masks()};

    for (constexpr int n{1001}, n_bits{sizeof(int) * 8}; const auto i : views::iota(1, n)) {
        const auto n_swapped{swap_bits(i, masks)};
        cout << setw(7) << i << ' ' << bitset<n_bits>(i) << '\n';
        cout << setw(7) << n_swapped << ' ' << bitset<n_bits>(n_swapped) << "\n\n";
    }

    return 0;
}

pair<int, int> initialize_bit_masks()
{
    constexpr int n_bits{sizeof(int) * 8};
    int mask_even_bits{};
    int mask_odd_bits{};

    for (const auto i : views::iota(0, n_bits)) {
        if (i & 1)
            mask_odd_bits = set_bit(mask_odd_bits, i);
        else
            mask_even_bits = set_bit(mask_even_bits, i);
    }

    return {mask_even_bits, mask_odd_bits};
}

int set_bit(const int n, const int i)
{
    return n | 1 << i;
}

int swap_bits(const int n, const pair<int, int>& masks)
{
    int left_shifted_number{n << 1};
    int right_shifted_number{n >> 1};

    const auto& [mask_even_bits, mask_odd_bits]{masks};
    const auto even_bits{left_shifted_number & mask_odd_bits};
    const auto odd_bits{right_shifted_number & mask_even_bits};

    return even_bits | odd_bits;
}
