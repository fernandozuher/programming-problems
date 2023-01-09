// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Result {

private:
    vector<int> _keyboard_costs, _usb_drive_costs;
    int _budget;
    int _can_be_spent;

    void _get_money_spent() {
        for (unsigned i {0}, n_keyboard_costs {static_cast<unsigned>(_keyboard_costs.size())}; i < n_keyboard_costs; i++) {
            
            if (_is_next_cost_equal_to_current_one(_keyboard_costs, i))
                continue;

            for (unsigned j {0}, n_usb_drive_costs {static_cast<unsigned>(_usb_drive_costs.size())}; j < n_usb_drive_costs; j++) {
                
                if (_is_next_cost_equal_to_current_one(_usb_drive_costs, j))
                    continue;

                const int sum {_keyboard_costs.at(i) + _usb_drive_costs.at(j)};

                if (_is_sum_inside_budget(sum))
                    _can_be_spent = _update_cost(sum);
                else
                    break;
            }
        }

        _can_be_spent = _can_be_spent ? _can_be_spent : -1;
    }

        bool _is_next_cost_equal_to_current_one(const vector<int> device_costs, const int current_index) const {
            return current_index < static_cast<int>(device_costs.size()) - 1 && device_costs[current_index] == device_costs[current_index + 1];
        }

        bool _is_sum_inside_budget(const int sum) const {
            return sum <= _budget;
        }

        int _update_cost(const int sum) const {
            return max(sum, _can_be_spent);
        }

public:
    Result(const vector<int> keyboard_cost, const vector<int> usb_drive_costs, const int budget) {
        _keyboard_costs = keyboard_cost;
        _usb_drive_costs = usb_drive_costs;
        _budget = budget;
        _can_be_spent = 0;

        _get_money_spent();
        print_result();
    }

        void print_result() const {
            cout << _can_be_spent;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> inputLine;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; inputLine.push_back(number));
    return inputLine;
}

int main() {
    const vector<int> inputLine {read_line_as_vector_int()};
    const int budget {inputLine.front()};

    vector<int> keyboard_costs {read_line_as_vector_int()};
    vector<int> usb_drive_costs {read_line_as_vector_int()};

    ranges::sort(keyboard_costs);
    ranges::sort(usb_drive_costs);

    Result result(keyboard_costs, usb_drive_costs, budget);

    return 0;
}
