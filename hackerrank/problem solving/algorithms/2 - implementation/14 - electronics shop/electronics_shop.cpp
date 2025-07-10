// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// C++20

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int calculate_money_spent(const vector<int>& keyboards, const vector<int>& usb_drives, int budget);

int main()
{
    int budget, n_keyboards, n_usb_drives;
    cin >> budget >> n_keyboards >> n_usb_drives;

    vector<int> keyboards = read_numbers(n_keyboards);
    vector<int> usb_drives = read_numbers(n_usb_drives);
    ranges::sort(keyboards);
    ranges::sort(usb_drives);

    auto x = ranges::unique(keyboards);
    auto y = ranges::unique(usb_drives);
    keyboards.erase(x.begin(), x.end());
    usb_drives.erase(y.begin(), y.end());

    cout << calculate_money_spent(keyboards, usb_drives, budget);

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x: numbers)
        cin >> x;
    return numbers;
}

int calculate_money_spent(const vector<int>& keyboards, const vector<int>& usb_drives, int budget)
{
    int max_spent{-1};

    // Cryptic, but really efficient ;-)
    for (auto end_usb{usb_drives.end()}; int keyboard : keyboards) {
        if (keyboard >= budget)
            break;

        int max_usb{budget - keyboard};
        auto it{upper_bound(usb_drives.begin(), end_usb, max_usb)};

        if (it != usb_drives.begin()) {
            int usb{*(--it)};
            int sum{keyboard + usb};
            if (sum > max_spent)
                max_spent = sum;
        }

        end_usb = ++it;
    }

    return max_spent;
}
