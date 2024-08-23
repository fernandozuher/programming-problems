// From C++23

#include <algorithm>
#include <cmath>
#include <iostream>
#include <print>
#include <ranges>
#include <set>
#include <vector>

using namespace std;

string generate_duplicated_string(int n);
vector<string> permutation_without_duplicates(const string& str);

int main()
{
    for (constexpr int n{5}; const int i : views::iota(1, n)) {
        const auto str{generate_duplicated_string(i)};
        println("original string: {}", str);
        ranges::copy(permutation_without_duplicates(str), ostream_iterator<string>(cout, "\n"));
        println("");
    }
    return 0;
}

string generate_duplicated_string(const int n)
{
    string str{views::iota(0, n) | views::transform([](const int x) { return 'a' + x; }) | ranges::to<string>()};
    return str + str;
}

vector<string> permutation_without_duplicates(const string& str)
{
    // A binary search tree structure (set) instead a hash (unordered_set) because I need
    // the characters of the string sorted to generate permutations after the first sorted string.
    set string_set(str.begin(), str.end());
    string deduplicated_string(string_set.begin(), string_set.end());
    println("deduplicated string: {}", deduplicated_string);
    const auto size{deduplicated_string.size()};
    println("characters = {}, permutations ({}!) = {}", size, size, tgamma(size + 1));

    vector<string> permutations;
    do {
        permutations.push_back(deduplicated_string);
    } while (ranges::next_permutation(deduplicated_string).found);
    return permutations;
}
