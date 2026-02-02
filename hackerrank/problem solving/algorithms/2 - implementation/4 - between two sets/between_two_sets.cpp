// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int between_two_sets(const vector<int>& a, const vector<int>& b);
template<class Func>
int reduce(const vector<int>& arr, Func func);

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector a{ read_numbers(n1) };
    vector b{ read_numbers(n2) };
    println("{}", between_two_sets(a, b));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int between_two_sets(const vector<int>& a, const vector<int>& b)
{
    int lcm_of_a{ reduce(a, lcm<int, int>) };
    int gcd_of_b{ reduce(b, gcd<int, int>) };
    return ranges::count_if(
        views::iota(lcm_of_a, gcd_of_b + 1) | views::stride(lcm_of_a),
        [gcd_of_b](auto i) { return gcd_of_b % i == 0; });
}

template<class Func>
int reduce(const vector<int>& arr, Func func)
{
    return *ranges::fold_left_first(arr, func);
}
