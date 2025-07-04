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
    int calculate_overcharge(int individual_share) const;
};

Bill_Division::Bill_Division(const input& data): item_not_eaten{data.item_not_eaten},
                                                 meal_costs{data.meal_costs},
                                                 amount_charged{data.amount_charged}
{
}


int Bill_Division::bon_appetit() const
{
    int individual_share{compute_actual_share()};
    return calculate_overcharge(individual_share);
}

int Bill_Division::compute_actual_share() const
{
    int sum{*ranges::fold_left_first(meal_costs, plus())};
    int splitting_cost_between_two_people{(sum - meal_costs.at(item_not_eaten)) / 2};
    return splitting_cost_between_two_people;
}

int Bill_Division::calculate_overcharge(int individual_share) const
{
    return individual_share != amount_charged ? amount_charged - individual_share : 0;
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
