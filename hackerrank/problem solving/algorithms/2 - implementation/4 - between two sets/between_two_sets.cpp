// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int between_two_sets(const vector<int>& a, const vector<int>& b);
int lcm_array(const vector<int>& arr);
int gcd_array(const vector<int>& arr);

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
    int lcm_of_a{ lcm_array(a) };
    int gcd_of_b{ gcd_array(b) };

    auto rng{
        views::iota(lcm_of_a, gcd_of_b + 1)
        | views::stride(lcm_of_a)
        | views::filter([gcd_of_b](auto i) { return gcd_of_b % i == 0; })
    };
    return static_cast<int>(ranges::distance(rng));
}

int lcm_array(const vector<int>& arr)
{
    return *ranges::fold_left_first(arr, lcm<int, int>);
}

int gcd_array(const vector<int>& arr)
{
    return *ranges::fold_left_first(arr, gcd<int, int>);
}
