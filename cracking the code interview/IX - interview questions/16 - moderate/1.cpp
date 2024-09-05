// From C++23 onwards

//#define NDEBUG
#include <cassert>
#include <print>
#include <ranges>

using namespace std;

void swap_without_temporary(int& a, int& b);

int main()
{
    for (constexpr int start{-15}, end{16}; const auto i : views::iota(start, end))
        for (const auto j : views::iota(start, end)) {
            if (i == j)
                continue;
            int a{i}, b{j};
            assert(pair(i, j) == pair(a, b));
            swap_without_temporary(a, b);
            println("{}, {} => {}, {}", i, j, a, b);
            assert(pair(i, j) == pair(b, a));
        }

    return 0;
}

void swap_without_temporary(int& a, int& b)
{
    b = a + b;
    a = b - a;
    b = b - a;
}
