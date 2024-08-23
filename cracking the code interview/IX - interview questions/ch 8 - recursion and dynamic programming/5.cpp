// From C++23

#include <print>
#include <ranges>

using namespace std;

int recursive_multiply(int a, int b);
int get_index_of_left_most_bit_set_from(int n);
int clear_bit(int n, int i);

int main()
{
    for (constexpr int n{6}; const auto i : views::iota(1, n))
        for (const auto j : views::iota(1, n))
            println("{} * {} = {}", i, j, recursive_multiply(i, j));
    return 0;
}

int recursive_multiply(const int a, int b)
{
    int result{};

    if (b > 0) {
        int i{get_index_of_left_most_bit_set_from(b)};
        b = clear_bit(b, i);
        result = a << i;
        result += recursive_multiply(a, b);
    }

    return result;
}

int get_index_of_left_most_bit_set_from(const int n)
{
    if (n <= 0)
        throw out_of_range("Number must be positive");

    for (const auto i : views::iota(0, static_cast<int>(sizeof(int)) * 8) | views::reverse)
        if (n & 1 << i)
            return i;
}

int clear_bit(const int n, const int i)
{
    return n & ~(1 << i);
}
