// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Electronics_Shop {
public:
    Electronics_Shop(const vector<int>& keyboard_cost, const vector<int>& usb_drive_costs, const int budget);
    int money_that_can_be_spent() const;

private:
    vector<int> keyboard_costs, usb_drive_costs;
    int budget;
    int money_can_be_spent;

    void calculate_money_spent();
    bool is_next_cost_equal_to_current_one(const vector<int>& device_costs, const int i) const;
    bool is_sum_affordable_by_budget(const int sum) const;
    int update_cost(const int sum) const;
};

    Electronics_Shop::Electronics_Shop(const vector<int>& keyboard_cost, const vector<int>& usb_drive_costs, const int budget)
        : keyboard_costs{keyboard_cost}, usb_drive_costs{usb_drive_costs}, budget{budget}, money_can_be_spent{}
    {
        calculate_money_spent();
    }

    int Electronics_Shop::money_that_can_be_spent() const
    {
        return money_can_be_spent;
    }

        void Electronics_Shop::calculate_money_spent()
        {
            for (int i{}, n_keyboard_costs = keyboard_costs.size(); i < n_keyboard_costs; ++i) {

                if (is_next_cost_equal_to_current_one(keyboard_costs, i))
                    continue;

                for (int j{}, n_usb_drive_costs = usb_drive_costs.size(); j < n_usb_drive_costs; ++j) {

                    if (is_next_cost_equal_to_current_one(usb_drive_costs, j))
                        continue;

                    int sum {keyboard_costs.at(i) + usb_drive_costs.at(j)};

                    if (is_sum_affordable_by_budget(sum))
                        money_can_be_spent = update_cost(sum);
                    else
                        break;
                }
            }

            money_can_be_spent = money_can_be_spent ? money_can_be_spent : -1;
        }

            bool Electronics_Shop::is_next_cost_equal_to_current_one(const vector<int>& device_costs, const int i) const
            {
                return i < device_costs.size() - 1 && device_costs.at(i) == device_costs.at(i + 1);
            }

            bool Electronics_Shop::is_sum_affordable_by_budget(const int sum) const
            {
                return sum <= budget;
            }

            int Electronics_Shop::update_cost(const int sum) const
            {
                return max(sum, money_can_be_spent);
            }

int main()
{
    int budget, n_keyboard_costs, n_usb_drive_costs;
    cin >> budget >> n_keyboard_costs >> n_usb_drive_costs;

    vector<int> keyboard_costs {read_int_array(n_keyboard_costs)};
    vector<int> usb_drive_costs {read_int_array(n_usb_drive_costs)};

    ranges::sort(keyboard_costs);
    ranges::sort(usb_drive_costs);

    Electronics_Shop obj{keyboard_costs, usb_drive_costs, budget};
    cout << obj.money_that_can_be_spent();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, [] {int x; cin >> x; return x;});
        return array;
    }
