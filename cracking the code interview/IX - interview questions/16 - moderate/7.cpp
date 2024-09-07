// From C++23 onwards

#include <cassert>
#include <print>
#include <ranges>

using namespace std;

void custom_number_max(int a, int b);
int number_max(int a, int b);
bool get_bit(int n, int index);
bool will_overflow(int a, int b);
bool will_underflow(int a, int b);

int main()
{
    for (constexpr int n{3}; const auto i : views::iota(-n, n + 1))
        for (const auto j : views::iota(-n, n + 1))
            custom_number_max(i, j);

    // To check under/overflow
    for (int min_int{numeric_limits<int>::min()}, max_int{numeric_limits<int>::max()};
         const auto i : {min_int, max_int})
        for (const auto j : {min_int, max_int})
            custom_number_max(i, j);
    return 0;
}

void custom_number_max(const int a, const int b)
{
    const auto max_n{number_max(a, b)};
    println("({}, {}) == max {}", a, b, max_n);
    assert(max(a, b) == max_n);
}

int number_max(const int a, const int b)
{
    if (will_overflow(a, b))
        return a;
    if (will_underflow(a, b))
        return b;

    int diff = a - b;
    constexpr int bit_signal_index = sizeof(int) * 8 - 1;
    int last_bit = get_bit(diff, bit_signal_index);
    return a * !last_bit + b * last_bit;
}

bool get_bit(const int n, const int index)
{
    return n & 1 << index;
}

bool will_overflow(const int a, const int b)
{
    return b < 0 && a >
        numeric_limits<int>::max() + b;
}

bool will_underflow(const int a, const int b)
{
    return b > 0 && a < numeric_limits<int>::min() + b;
}
