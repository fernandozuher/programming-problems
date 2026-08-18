// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

struct input {
    int item_not_eaten{};
    vector<int> meal_costs;
    int amount_charged{};
};

input read_input();
int bon_appetit(const input& data);

int main()
{
    input data{ read_input() };
    int charged{ bon_appetit(data) };
    charged ? println("{}", charged) : println("Bon Appetit");
    return 0;
}

input read_input()
{
    int n = morfo::read();
    return { .item_not_eaten = morfo::read(), .meal_costs = morfo::read(n), .amount_charged = morfo::read() };
}

// n: length of data.meal_costs
// T: O(n)
// S: O(1) extra space
int bon_appetit(const input& data)
{
    int total_cost{ morfo::sum(data.meal_costs) };
    int total_shared_cost{ total_cost - data.meal_costs.at(data.item_not_eaten) };
    total_shared_cost /= 2;
    return data.amount_charged - total_shared_cost;
}
