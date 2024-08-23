// From C++23

#include <algorithm>
#include <cmath>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

string generate_string(int n);
vector<string> permutation(string str);

int main()
{
    for (constexpr int n{5}; const int i : views::iota(1, n)) {
        println("characters = {}, permutations ({}!) = {}", i, i, tgamma(i + 1));
        const auto str{generate_string(i)};
        ranges::copy(permutation(str), ostream_iterator<string>(cout, "\n"));
        println("");
    }
    return 0;
}

string generate_string(const int n)
{
    return views::iota(0, n) | views::transform([](const int x) { return 'a' + x; }) | ranges::to<string>();
}

vector<string> permutation(string str)
{
    vector<string> permutations;
    do {
        permutations.push_back(str);
    } while (ranges::next_permutation(str).found);
    return permutations;
}
