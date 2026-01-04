// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// C++23

import std;
using namespace std;

struct input {
    int item_not_eaten{};
    vector<int> meal_costs;
    int amount_charged{};
};

input read_input();
vector<int> read_numbers(int n);
int bon_appetit(const input& data);

int main()
{
    input data{ read_input() };
    if (int charged{ bon_appetit(data) }; charged)
        println("{}", charged);
    else
        println("Bon Appetit");

    return 0;
}

input read_input()
{
    int n, item_not_eaten;
    cin >> n >> item_not_eaten;
    vector<int> meal_costs{ read_numbers(n) };
    int amount_charged;
    cin >> amount_charged;
    return { item_not_eaten, meal_costs, amount_charged };
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array data.meal_costs
// T: O(n)
// S: O(1) extra space
int bon_appetit(const input& data)
{
    int total_cost{ *ranges::fold_left_first(data.meal_costs, plus()) };
    int total_shared_cost{ total_cost - data.meal_costs.at(data.item_not_eaten) };
    total_shared_cost /= 2;
    return data.amount_charged - total_shared_cost;
}
