// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// From C++23 onwards

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct input {
    int item_anna_didnt_consume{};
    vector<int> cost_of_each_meal;
    int brian_charged_anna{};
};

class Bill_Division {
public:
    explicit Bill_Division(const input& data);
    [[nodiscard]] int bon_appetit();
    [[nodiscard]] int brian_overcharged_anna() const;

private:
    int item_anna_didnt_consume;
    vector<int> cost_of_each_meal;
    int brian_charged_anna;
    int brian_overcharged{};

    int calculate_anna_cost();
    void how_much_brian_overcharged(int anna_cost);
};

Bill_Division::Bill_Division(const input& data): item_anna_didnt_consume{data.item_anna_didnt_consume},
                                                 cost_of_each_meal{data.cost_of_each_meal},
                                                 brian_charged_anna{data.brian_charged_anna} {}


int Bill_Division::bon_appetit()
{
    int anna_cost{calculate_anna_cost()};
    how_much_brian_overcharged(anna_cost);
    return brian_overcharged_anna();
}

int Bill_Division::calculate_anna_cost()
{
    int sum{*ranges::fold_left_first(cost_of_each_meal, plus())};
    return (sum - cost_of_each_meal.at(item_anna_didnt_consume)) / 2;
}

void Bill_Division::how_much_brian_overcharged(const int anna_cost)
{
    if (anna_cost != brian_charged_anna)
        brian_overcharged = brian_charged_anna - anna_cost;
}

int Bill_Division::brian_overcharged_anna() const
{
    return brian_overcharged;
}

//////////////////////////////////////////////////

template<class T = int>
vector<T> read(int n);
void print_output(int charged);

int main()
{
    int n;
    input data;
    cin >> n >> data.item_anna_didnt_consume;
    data.cost_of_each_meal = read(n);
    cin >> data.brian_charged_anna;
    print_output(Bill_Division{data}.bon_appetit());

    return 0;
}

template<class T>
vector<T> read(const int n)
{
    vector<T> array(n);
    copy_n(istream_iterator<T>(cin), n, array.begin());
    return array;
}

void print_output(const int charged)
{
    if (charged)
        cout << charged;
    else
        cout << "Bon Appetit";
}
