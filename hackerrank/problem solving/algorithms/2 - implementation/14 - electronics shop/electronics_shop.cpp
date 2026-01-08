// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
void pre_process_input(vector<int>& arr);
int calculate_money_spent(const vector<int>& keyboards, const vector<int>& usb_drives, int budget);

int main()
{
    int budget, n_keyboards, n_usb_drives;
    cin >> budget >> n_keyboards >> n_usb_drives;

    vector keyboards{ read_numbers(n_keyboards) };
    vector usb_drives{ read_numbers(n_usb_drives) };
    pre_process_input(keyboards);
    pre_process_input(usb_drives);

    cout << calculate_money_spent(keyboards, usb_drives, budget);

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

void pre_process_input(vector<int>& arr)
{
    ranges::sort(arr);
    auto x{ ranges::unique(arr) };
    arr.erase(x.begin(), x.end());
}

// n: length of array keyboards
// m: length of array usb_drives
// T: O(n + m)
// S: O(1) extra space
int calculate_money_spent(const vector<int>& keyboards, const vector<int>& usb_drives, int budget)
{
    if (keyboards[0] >= budget || usb_drives[0] >= budget)
        return -1;

    int max_spent{ -1 };
    for (int idx_k{}, idx_ud = usb_drives.size() - 1; idx_k < keyboards.size() && idx_ud >= 0;) {
        if (keyboards[idx_k] >= budget)
            break;

        int current_sum{ keyboards[idx_k] + usb_drives[idx_ud] };
        if (current_sum == budget)
            return budget;

        if (current_sum > budget)
            --idx_ud;
        else {
            max_spent = max(max_spent, current_sum);
            ++idx_k;
        }
    }

    return max_spent;
}
