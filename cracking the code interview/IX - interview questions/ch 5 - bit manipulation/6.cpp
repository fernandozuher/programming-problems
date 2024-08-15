// From C++23

#include <algorithm>
#include <bitset>
#include <print>
#include <ranges>

using namespace std;

size_t bits_to_flip(int a, int b);
bool get_bit(int n, int i);

int main()
{
    println("A, binaryA -> B, binaryB? bits_to_fip");
    for (constexpr int n{101}; const int i : views::iota(0, n)) {
        for (const int j : views::iota(i + 1, n)) {
            bitset<8> a(i);
            bitset<8> b(j);
            println("{}, {} -> {}, {}? {}", i, a.to_string(), j, b.to_string(), bits_to_flip(i, j));
        }
    }
    return 0;
}

size_t bits_to_flip(const int a, const int b)
{
    const auto range{views::iota(0, static_cast<int>(sizeof(int)) * 8)};
    const auto bits{a ^ b};
    const auto count_bits_one{[&bits](const int sum, const int i) { return sum + get_bit(bits, i); }};
    return ranges::fold_left(range, 0, count_bits_one);
    // return bitset<static_cast<int>(sizeof(int)) * 8>(a ^ b).count();
}

bool get_bit(const int n, const int i)
{
    return n & 1 << i;
}
