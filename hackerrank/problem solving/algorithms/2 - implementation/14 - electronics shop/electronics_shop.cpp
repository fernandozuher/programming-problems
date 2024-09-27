// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

#include <iostream>
#include <set>

using namespace std;

set<int> custom_read(int n, int budget);
int calculate_money_spent(const set<int>& keyboard_costs, const set<int>& usb_drive_costs, int budget);
int look_for_max_complement(const set<int>& usb_drive_costs, int limit);

int main()
{
    int budget, n_keyboard_costs, n_usb_drive_costs;
    cin >> budget >> n_keyboard_costs >> n_usb_drive_costs;
    const set<int> keyboard_costs{custom_read(n_keyboard_costs, budget)};
    const set<int> usb_drive_costs{custom_read(n_usb_drive_costs, budget)};
    cout << calculate_money_spent(keyboard_costs, usb_drive_costs, budget);
    return 0;
}

set<int> custom_read(int n, const int budget)
{
    set<int> elements; // Because it stores unique values in a sorted way
    for (int x; n-- && cin >> x;)
        if (x < budget) // No include more than or equal to budget because it is useless to compare to it
            elements.insert(x);
    return elements;
}

int calculate_money_spent(const set<int>& keyboard_costs, const set<int>& usb_drive_costs, const int budget)
{
    int money_can_be_spent{-1};
    for (const auto keyboard_cost : keyboard_costs) {
        int limit{budget - keyboard_cost};
        if (int max_complement = look_for_max_complement(usb_drive_costs, limit); max_complement) {
            max_complement += keyboard_cost;
            money_can_be_spent = max(max_complement, money_can_be_spent);
        }
    }
    return money_can_be_spent;
}

int look_for_max_complement(const set<int>& usb_drive_costs, const int limit)
{
    if (const auto usb_cost{usb_drive_costs.upper_bound(limit)}; usb_cost != usb_drive_costs.begin())
        return *prev(usb_cost, 1);
    return 0;
}
