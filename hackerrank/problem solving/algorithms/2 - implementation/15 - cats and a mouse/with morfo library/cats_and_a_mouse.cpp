// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// C++23

import morfo;
import std;
using namespace std;

string find_nearest_cat_or_not(const vector<int>& positions);

int main()
{
    int n = morfo::read();
    constexpr int n_positions{ 3 };
    for (int i{}; i < n; ++i)
        println("{}", find_nearest_cat_or_not(morfo::read(n_positions)));
    return 0;
}

// T: O(1)
// S: O(1) extra space
string find_nearest_cat_or_not(const vector<int>& positions)
{
    int cat_a{ positions[0] }, cat_b{ positions[1] }, mouse{ positions[2] };
    int cat_a_from_mouse{ abs(cat_a - mouse) };
    int cat_b_from_mouse{ abs(cat_b - mouse) };

    if (cat_a_from_mouse < cat_b_from_mouse)
        return "Cat A";
    if (cat_a_from_mouse > cat_b_from_mouse)
        return "Cat B";
    return "Mouse C";
}
