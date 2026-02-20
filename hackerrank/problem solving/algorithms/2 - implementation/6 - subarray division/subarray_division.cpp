// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month);

int main()
{
    int n;
    cin >> n;
    vector chocolate_squares{ read_numbers(n) };
    constexpr int n_day_month{ 2 };
    vector day_month{ read_numbers(n_day_month) };
    cout << birthday(chocolate_squares, day_month);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array chocolate_squares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month)
{
    int day{ day_month[0] };
    int month{ day_month[1] };
    if (month > chocolate_squares.size())
        return 0;

    int sum{ *ranges::fold_left_first(chocolate_squares.begin(), chocolate_squares.begin() + month, plus{}) };
    int count{ sum == day };

    for (int i{ month }, n = chocolate_squares.size(); i < n; ++i) {
        sum += chocolate_squares.at(i) - chocolate_squares.at(i - month);
        count += sum == day;
    }

    return count;
}
