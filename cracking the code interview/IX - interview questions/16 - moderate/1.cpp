// From C++23 onwards

//#define NDEBUG
#include <cassert>
#include <print>
#include <ranges>

using namespace std;

void swap_without_temporary(int& a, int& b);

int main()
{
    for (constexpr int start{numeric_limits<int>::min()}, end{numeric_limits<int>::max()};
         const auto i : views::iota(start, end))
        for (const auto j : views::iota(start, end)) {
            if (i == j)
                continue;
            int a{i}, b{j};

            assert(pair(i, j) == pair(a, b));
            swap_without_temporary(a, b);
            //println("{}, {} => {}, {}", i, j, b, a);
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
