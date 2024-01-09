// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);
void print_output(const int charged);

class Bill_Division {
public:
    Bill_Division(const vector<int>& cost_of_each_meal, const int item_anna_didnt_consume, const int brian_charged_anna)
        : cost_of_each_meal{cost_of_each_meal}, item_anna_didnt_consume{item_anna_didnt_consume},
        brian_charged_anna{brian_charged_anna}, brian_overcharged_anna{}
    {
        bon_appetit();
    }

    int brian_overcharged() const
    {
        return brian_overcharged_anna;
    }

private:
    vector<int> cost_of_each_meal;
    int item_anna_didnt_consume;
    int brian_charged_anna;
    int brian_overcharged_anna;

    void bon_appetit()
    {
        int anna_cost {calculate_anna_cost()};
        calculate_how_much_brian_overcharged_anna(anna_cost);
    }

        int calculate_anna_cost()
        {
            int sum {accumulate(cost_of_each_meal.begin(), cost_of_each_meal.end(), 0)};
            int anna_cost {(sum - cost_of_each_meal.at(item_anna_didnt_consume)) / 2};
            return anna_cost;
        }

        void calculate_how_much_brian_overcharged_anna(const int anna_cost)
        {
            if (anna_cost != brian_charged_anna)
                brian_overcharged_anna = brian_charged_anna - anna_cost;
        }
};

int main()
{
    int n, item_anna_didnt_consume;
    cin >> n >> item_anna_didnt_consume;

    vector<int> cost_of_each_meal {read_int_array(n)};
    int brian_charged_anna;
    cin >> brian_charged_anna;

    Bill_Division obj{cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna};
    print_output(obj.brian_overcharged());

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int x; cin >> x; return x;});
        return array;
    }

    void print_output(const int charged)
    {
        if (charged)
            cout << charged;
        else
            cout << "Bon Appetit";
    }
