// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct input {
    int item_not_eaten{};
    vector<int> meal_costs;
    int amount_charged{};
};

class Bill_Division {
public:
    explicit Bill_Division(const input& data);
    int bon_appetit() const;

private:
    int item_not_eaten;
    vector<int> meal_costs;
    int amount_charged;

    int compute_actual_share() const;
};

Bill_Division::Bill_Division(const input& data): item_not_eaten{data.item_not_eaten},
                                                 meal_costs{data.meal_costs},
                                                 amount_charged{data.amount_charged}
{
}


int Bill_Division::bon_appetit() const
{
    return amount_charged - compute_actual_share();
}

int Bill_Division::compute_actual_share() const
{
    int total_cost{*ranges::fold_left_first(meal_costs, plus())};
    int total_shared_cost{total_cost - meal_costs.at(item_not_eaten)};
    return total_shared_cost / 2;
}

//////////////////////////////////////////////////

input read_input();
vector<int> read_numbers(int n);
void print_output(int charged);

int main()
{
    input data{read_input()};
    print_output(Bill_Division{data}.bon_appetit());
    return 0;
}

input read_input()
{
    int n, item_not_eaten;
    cin >> n >> item_not_eaten;
    vector<int> meal_costs = read_numbers(n);
    int amount_charged;
    cin >> amount_charged;
    return {item_not_eaten, meal_costs, amount_charged};
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x : numbers)
        cin >> x;
    return numbers;
}

void print_output(int charged)
{
    if (charged)
        cout << charged << '\n';
    else
        cout << "Bon Appetit\n";
}
