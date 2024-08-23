// From C++23

#include <iostream>
#include <print>
#include <ranges>

using namespace std;

void pairs_of_parentheses_combinations(int n);
void pairs_of_parentheses_combinations(string& str, int open_parens, int close_parens);

int main()
{
    for (constexpr int n{5}; const auto i : views::iota(1, n)) {
        println("{} pair(s) of parentheses:", i);
        pairs_of_parentheses_combinations(i);
        println("");
    }
    return 0;
}

void pairs_of_parentheses_combinations(const int n)
{
    string str;
    pairs_of_parentheses_combinations(str, n, n);
}

void pairs_of_parentheses_combinations(string& str, const int open_parens, const int close_parens)
{
    if (!open_parens && !close_parens) {
        cout << str << '\n';
        return;
    }

    if (open_parens) {
        str += '(';
        pairs_of_parentheses_combinations(str, open_parens - 1, close_parens);
        str.pop_back();
    }

    if (close_parens > open_parens) {
        str += ')';
        pairs_of_parentheses_combinations(str, open_parens, close_parens - 1);
        str.pop_back();
    }
}
