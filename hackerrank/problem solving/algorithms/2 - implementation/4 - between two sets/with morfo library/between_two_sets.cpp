// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int between_two_sets(const vector<long long>& a, const vector<long long>& b);

int main()
{
    morfo::skip_input_ln();
    vector<long long> a = morfo::readln();
    vector<long long> b = morfo::readln();
    println("{}", between_two_sets(a, b));
    return 0;
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
int between_two_sets(const vector<long long>& a, const vector<long long>& b)
{
    // long long, not int: the lcm of ten values under 100 reaches 3.1e15,
    // and morfo::lcm returns the element type — a true lcm outside it is
    // std::lcm's own precondition, which libstdc++ checks and traps.
    long long lcm_of_a{ morfo::lcm(a) };
    long long gcd_of_b{ morfo::gcd(b) };

    // views::iota requires the bound to be reachable from the value, so
    // the no-multiples-fit case cannot go through the range below.
    if (lcm_of_a > gcd_of_b)
        return 0;

    return ranges::count_if(
        views::iota(lcm_of_a, gcd_of_b + 1) | views::stride(lcm_of_a),
        [gcd_of_b](auto i) { return gcd_of_b % i == 0; });
}
