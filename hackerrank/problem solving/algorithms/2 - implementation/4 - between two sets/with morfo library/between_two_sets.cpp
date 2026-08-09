// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int between_two_sets(const vector<int>& a, const vector<int>& b);
template<class Func>
int reduce(const vector<int>& arr, Func func);

int main()
{
    morfo::skip_input_ln();
    vector<int> a = morfo::readln();
    vector<int> b = morfo::readln();
    println("{}", between_two_sets(a, b));
    return 0;
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
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
