// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class Result {

private:
    vector<int> _cost_of_each_meal;
    int _item_anna_didnt_consume;
    int _brian_charged_anna;
    string _brian_overcharged_anna;

    void _bon_appetit() {
        const int anna_cost {_calculate_anna_cost()};
        _brian_overcharged_anna = _check_if_brian_overcharged_anna(anna_cost);
    }

        int _calculate_anna_cost() {
            const int sum {accumulate(_cost_of_each_meal.begin(), _cost_of_each_meal.end(), 0)};
            const int anna_cost {(sum - _cost_of_each_meal.at(_item_anna_didnt_consume)) / 2};
            return anna_cost;
        }

        string _check_if_brian_overcharged_anna(const int anna_cost) {
            if (anna_cost == _brian_charged_anna)
                return "Bon Appetit";
            else {
                const int brian_overcharged_ana {_brian_charged_anna - anna_cost};
                return to_string(brian_overcharged_ana);
            }
        }

public:
    Result(const vector<int> cost_of_each_meal, const int item_anna_didnt_consume, const int brian_charged_anna) {
        _cost_of_each_meal = cost_of_each_meal;
        _item_anna_didnt_consume = item_anna_didnt_consume;
        _brian_charged_anna = brian_charged_anna;
        _brian_overcharged_anna = "";

        _bon_appetit();
        print_result();
    }

        void print_result() const {
            cout << _brian_overcharged_anna;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> numbers;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; numbers.push_back(number));
    return numbers;
}

int main() {
    const vector<int> input1 {read_line_as_vector_int()};
    const int item_anna_didnt_consume {input1.back()};

    const vector<int> cost_of_each_meal {read_line_as_vector_int()};
    const vector<int> brian_charged_anna {read_line_as_vector_int()};

    Result result(cost_of_each_meal, item_anna_didnt_consume, brian_charged_anna.front());

    return 0;
}
