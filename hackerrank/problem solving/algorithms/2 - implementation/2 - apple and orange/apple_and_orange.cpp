// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// C++23

import std;
using namespace std;

struct house_t {
    int start{}, end{};

    [[nodiscard]] bool contains(int position) const
    {
        return start <= position && position <= end;
    }
};

struct fruit_tree_t {
    int tree_location{};
    vector<int> fruit_distances;
};

tuple<house_t, fruit_tree_t, fruit_tree_t> read_input();
vector<int> read_numbers(int n);
int count_fruits_on_house(const fruit_tree_t& fruit_tree, const house_t& house);

int main()
{
    auto [house, apple_tree, orange_tree] { read_input() };
    println("{}", count_fruits_on_house(apple_tree, house));
    println("{}", count_fruits_on_house(orange_tree, house));
    return 0;
}

tuple<house_t, fruit_tree_t, fruit_tree_t> read_input()
{
    house_t house;
    cin >> house.start >> house.end;

    fruit_tree_t apple_tree, orange_tree;
    cin >> apple_tree.tree_location >> orange_tree.tree_location;

    int n_apples, n_oranges;
    cin >> n_apples >> n_oranges;

    apple_tree.fruit_distances = read_numbers(n_apples);
    orange_tree.fruit_distances = read_numbers(n_oranges);

    return { house, apple_tree, orange_tree };
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array fruit_tree.fruit_distances
// T: O(n)
// S: O(1) extra space
int count_fruits_on_house(const fruit_tree_t& fruit_tree, const house_t& house)
{
    return ranges::count_if(fruit_tree.fruit_distances, [&fruit_tree, &house](auto distance) {
        return house.contains(fruit_tree.tree_location + distance);
        });
}
