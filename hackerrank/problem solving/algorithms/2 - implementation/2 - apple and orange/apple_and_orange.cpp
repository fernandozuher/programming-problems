// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>

using namespace std;

struct house_t {
    int start{}, end{};

    bool contains(int position) const
    {
        return start <= position && position <= end;
    }
};

struct fruit_tree {
    int tree_location{};
    vector<int> fruit_distances;
};

tuple<house_t, fruit_tree, fruit_tree> read_input();
vector<int> read_numbers(int n);
int count_fruits_on_house(const fruit_tree& fruit, const house_t& house);

int main()
{
    auto [house, apple_tree, orange_tree]{read_input()};
    cout << count_fruits_on_house(apple_tree, house) << '\n';
    cout << count_fruits_on_house(orange_tree, house) << '\n';
    return 0;
}

tuple<house_t, fruit_tree, fruit_tree> read_input()
{
    house_t house;
    cin >> house.start >> house.end;

    fruit_tree apple_tree, orange_tree;
    cin >> apple_tree.tree_location >> orange_tree.tree_location;

    int n_apples, n_oranges;
    cin >> n_apples >> n_oranges;

    apple_tree.fruit_distances = read_numbers(n_apples);
    orange_tree.fruit_distances = read_numbers(n_oranges);

    return {house, apple_tree, orange_tree};
}

vector<int> read_numbers(int n)
{
    return views::iota(0, n) | views::transform([](auto) {
        int x;
        cin >> x;
        return x;
    }) | ranges::to<vector>();
}

int count_fruits_on_house(const fruit_tree& fruit, const house_t& house)
{
    return ranges::count_if(fruit.fruit_distances, [&fruit, &house](auto distance) {
        return house.contains(fruit.tree_location + distance);
    });
}
