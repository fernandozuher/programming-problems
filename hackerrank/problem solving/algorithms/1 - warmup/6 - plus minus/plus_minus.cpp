// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
vector<double> plus_minus(const vector<int>& arr);
void print_ratios(const vector<double>& ratios);

int main()
{
    int n;
    cin >> n;
    vector arr{ read_numbers(n) };
    vector ratios{ plus_minus(arr) };
    print_ratios(ratios);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
vector<double> plus_minus(const vector<int>& arr)
{
    int positive{}, negative{}, zero{};

    for (int number : arr)
        if (number > 0)
            ++positive;
        else if (number < 0)
            ++negative;
        else
            ++zero;

    double n{ static_cast<double>(arr.size()) };
    return { positive / n, negative / n, zero / n };
}

void print_ratios(const vector<double>& ratios)
{
    cout << fixed << setprecision(6);
    for (auto ratio : ratios)
        cout << ratio << '\n';
}
