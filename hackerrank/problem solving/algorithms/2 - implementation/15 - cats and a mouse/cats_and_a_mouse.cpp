// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct positions {
    int cat_a_position;
    int cat_b_position;
    int mouse_position;
};

positions read_animals_positions();
string find_nearest_cat_or_not(const positions& animals_positions);

int main()
{
    int n;
    cin >> n;
    vector<string> nearest_cats_or_not(n);
    ranges::generate(nearest_cats_or_not, [] { return find_nearest_cat_or_not(read_animals_positions()); });
    ranges::copy(nearest_cats_or_not, ostream_iterator<string>(cout, "\n"));
    return 0;
}

positions read_animals_positions()
{
    int a, b, c;
    cin >> a >> b >> c;
    return {a, b, c};
}

string find_nearest_cat_or_not(const positions& animals_positions)
{
    int cat_a_position_from_mouse{abs(animals_positions.cat_a_position - animals_positions.mouse_position)};
    int cat_b_position_from_mouse{abs(animals_positions.cat_b_position - animals_positions.mouse_position)};

    if (cat_a_position_from_mouse < cat_b_position_from_mouse)
        return "Cat A";
    if (cat_a_position_from_mouse > cat_b_position_from_mouse)
        return "Cat B";
    return "Mouse C";
}
