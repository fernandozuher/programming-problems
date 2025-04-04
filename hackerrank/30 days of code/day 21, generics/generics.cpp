// https://www.hackerrank.com/challenges/30-generics/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read_input();
template<class T = int>
void print_vector(const vector<T>& v);

int main()
{
    vector numbers{read_input()};
    vector strings{read_input<string>()};
    print_vector(numbers);
    print_vector(strings);
    return 0;
}

template<class T>
vector<T> read_input()
{
    int n;
    cin >> n;
    return views::iota(0, n) | views::transform([](auto) { T x; cin >> x; return x; }) | ranges::to<vector<T>>();
}

template<class T>
void print_vector(const vector<T>& v)
{
    ranges::copy(v, ostream_iterator<T>(cout, "\n"));
}
