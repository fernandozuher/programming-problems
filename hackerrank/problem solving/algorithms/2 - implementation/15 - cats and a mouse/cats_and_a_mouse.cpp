// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true
// C++23

import std;
using namespace std;

tuple<int, int, int> read_positions();
string find_nearest_cat_or_not(const tuple<int, int, int>& positions);

int main()
{
    int n;
    cin >> n;
    for (int i{}; i < n; ++i)
        println("{}", find_nearest_cat_or_not(read_positions()));
    return 0;
}

tuple<int, int, int> read_positions()
{
    int cat_a, cat_b, mouse;
    cin >> cat_a >> cat_b >> mouse;
    return { cat_a, cat_b, mouse };
}

// T: O(1)
// S: O(1) extra space
string find_nearest_cat_or_not(const tuple<int, int, int>& positions)
{
    auto [cat_a, cat_b, mouse] = positions;
    int cat_a_from_mouse{ abs(cat_a - mouse) };
    int cat_b_from_mouse{ abs(cat_b - mouse) };

    if (cat_a_from_mouse < cat_b_from_mouse)
        return "Cat A";
    if (cat_a_from_mouse > cat_b_from_mouse)
        return "Cat B";
    return "Mouse C";
}
