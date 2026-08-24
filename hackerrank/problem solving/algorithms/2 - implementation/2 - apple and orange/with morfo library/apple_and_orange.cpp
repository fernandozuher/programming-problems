// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

struct house_t {
    int start{}, end{};

    bool contains(int position) const
    {
        return start <= position && position <= end;
    }
};

struct fruit_tree_t {
    int tree_location{};
    vector<int> fruit_distances;
};

tuple<house_t, fruit_tree_t, fruit_tree_t> read_input();
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
    auto [house_start, house_end] = morfo::read<int, int>();
    house_t house{ house_start, house_end };

    auto [apple_tree_location, orange_tree_location] = morfo::read<int, int>();
    auto [n_apples, n_oranges] = morfo::read<int, int>();

    vector<int> apple_distances = morfo::read(n_apples);
    vector<int> orange_distances = morfo::read(n_oranges);

    fruit_tree_t apple_tree{ apple_tree_location, apple_distances };
    fruit_tree_t orange_tree{ orange_tree_location, orange_distances };

    return { house, apple_tree, orange_tree };
}

// n: length of fruit_tree.fruit_distances
// T: O(n)
// S: O(1) extra space
int count_fruits_on_house(const fruit_tree_t& fruit_tree, const house_t& house)
{
    return ranges::count_if(fruit_tree.fruit_distances, [&fruit_tree, &house](auto distance) {
        return house.contains(fruit_tree.tree_location + distance);
        });
}
