// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
string find_nearest_cat_or_not(const vector<int>& positions);

int main()
{
    int n;
    cin >> n;
    vector<string> nearest_cat_or_not(n);
    for (auto& x : nearest_cat_or_not)
        x = find_nearest_cat_or_not(read_numbers(3));
    for (auto& x : nearest_cat_or_not)
        cout << x << '\n';

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x : numbers)
        cin >> x;
    return numbers;
}

string find_nearest_cat_or_not(const vector<int>& positions)
{
    int cat_a{positions.at(0)};
    int cat_b{positions.at(1)};
    int mouse{positions.at(2)};
    int cat_a_from_mouse{abs(cat_a - mouse)};
    int cat_b_from_mouse{abs(cat_b - mouse)};

    if (cat_a_from_mouse < cat_b_from_mouse)
        return "Cat A";
    if (cat_a_from_mouse > cat_b_from_mouse)
        return "Cat B";
    return "Mouse C";
}
