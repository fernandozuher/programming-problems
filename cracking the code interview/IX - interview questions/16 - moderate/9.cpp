// From C++23 onwards

#include <algorithm>
#include <cassert>
#include <iostream>
#include <print>
#include <ranges>

using namespace std;

struct assert_properties {
    int i{}, j{};
    char operator_type{};
    int result{};
};

int operations(char operator_type, int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int division_between_positives(int a, int b);
int to_positive(int n);
int to_negative(int n);
void assert_output(const assert_properties& p);

int minus_one{numeric_limits<int>::max() + numeric_limits<int>::min()};

int main()
{
    for (const auto operator_type : {'*', '-', '/'}) {
        println("Operation: {}", operator_type);
        for (constexpr int start{-3}, end{4}; const auto i : views::iota(start, end)) {
            println(".....");
            for (const auto j : views::iota(start, end)) {
                print("{} {} {} = ", i, operator_type, j);
                int result;
                try {
                    result = operations(operator_type, i, j);
                    println("{}", result);
                }
                catch (const invalid_argument& error) {
                    cout << error.what() << '\n';
                    continue;
                }
                assert_output({i, j, operator_type, result});
            }
        }
        println("________________________________");
    }
    return 0;
}

int operations(const char operator_type, const int a, const int b)
{
    if (operator_type == '*')
        return multiply(a, b);
    if (operator_type == '-')
        return subtract(a, b);
    if (operator_type == '/')
        return divide(a, b);
    return 0;
}

int multiply(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    int start, end, add_operand;
    if (a > 0 && b > 0)
        tie(start, end, add_operand) = tuple{0, b, a};
    else if (a > 0 || b > 0)
        tie(start, end, add_operand) = a > 0 ? tuple{0, a, b} : tuple{0, b, a};
    else {
        int positive_a{};
        for ([[maybe_unused]] const int i : views::iota(a, 0))
            positive_a += 1;
        tie(start, end, add_operand) = tuple{b, 0, positive_a};
    }

    int result{};
    for ([[maybe_unused]] const int i : views::iota(start, end))
        result += add_operand;
    return result;
}

int subtract(int a, int b)
{
    b = b > 0 ? to_negative(b) : to_positive(b);
    return a + b;
}

int divide(int a, int b)
{
    if (b == 0)
        throw invalid_argument("Division can't be by zero.");
    if (a == 0)
        return 0;
    if (a == b)
        return 1;

    int result{division_between_positives(to_positive(a), to_positive(b))};
    return (a < 0 && b > 0) || (a > 0 && b < 0) ? to_negative(result) : result;
}

int division_between_positives(int a, int b)
{
    if (a < b)
        return 0;

    int quot{}, sum{};
    for (; sum < a; ++quot)
        sum += b;
    return sum > a ? quot + minus_one : quot;
}

int to_positive(int n)
{
    if (n >= 0)
        return n;
    return static_cast<int>(views::iota(n, 0).size());
}

int to_negative(int n)
{
    if (n <= 0)
        return n;

    int negative_n{};
    for ([[maybe_unused]] const int i : views::iota(0, n))
        negative_n += minus_one;
    return negative_n;
}

void assert_output(const assert_properties& p)
{
    if (p.operator_type == '*')
        assert(p.i * p.j == p.result);
    else if (p.operator_type == '-')
        assert(p.i - p.j == p.result);
    else
        assert(p.i / p.j == p.result);
}
