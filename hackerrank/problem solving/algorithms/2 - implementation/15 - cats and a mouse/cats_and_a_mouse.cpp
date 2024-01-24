// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Cats_And_A_Mouse {
public:
    Cats_And_A_Mouse(const vector<int>& cats_and_mouse_positions);
    string nearest_cat_or_not() const;

private:
    int cat_a_position;
    int cat_b_position;
    int mouse_position;
    string closest_cat_or_not;

    void find_nearest_cat_or_not();
};

    Cats_And_A_Mouse::Cats_And_A_Mouse(const vector<int>& cats_and_mouse_positions):
        cat_a_position{cats_and_mouse_positions.front()},
        cat_b_position{cats_and_mouse_positions.at(1)},
        mouse_position{cats_and_mouse_positions.back()}
    {
        find_nearest_cat_or_not();
    }

    string Cats_And_A_Mouse::nearest_cat_or_not() const
    {
        return closest_cat_or_not;
    }

    void Cats_And_A_Mouse::find_nearest_cat_or_not()
    {
        int cat_a_position_from_mouse {abs(cat_a_position - mouse_position)};
        int cat_b_position_from_mouse {abs(cat_b_position - mouse_position)};

        if (cat_a_position_from_mouse < cat_b_position_from_mouse)
            closest_cat_or_not = "Cat A";
        else if (cat_a_position_from_mouse > cat_b_position_from_mouse)
            closest_cat_or_not = "Cat B";
        else
            closest_cat_or_not = "Mouse C";
    }

int main()
{
    int n;
    cin >> n;
    vector<string> nearest_cats_or_not(n);

    for (int i{}, animals{3}; i < n; ++i) {
        vector<int> positions {read_int_array(animals)};
        Cats_And_A_Mouse obj{positions};
        nearest_cats_or_not[i] = obj.nearest_cat_or_not();
    }

    for (const auto& closest_cat_or_not : nearest_cats_or_not)
        cout << closest_cat_or_not << '\n';

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int x; cin >> x; return x;});
        return array;
    }
