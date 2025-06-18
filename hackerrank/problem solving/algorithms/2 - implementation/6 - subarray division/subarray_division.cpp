// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month);

int main()
{
    int n;
    cin >> n;
    vector chocolate_squares{read_numbers(n)};
    constexpr int n_day_month{2};
    vector day_month{read_numbers(n_day_month)};
    cout << birthday(chocolate_squares, day_month);
    return 0;
}

vector<int> read_numbers(int n)
{
    return views::repeat(0, n)
           | views::transform([](auto) {int x; cin >> x; return x;})
           | ranges::to<vector>();
}

int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month)
{
    int day{day_month[0]};
    int month{day_month[1]};
    if (month > chocolate_squares.size())
        return 0;

    int sum{*ranges::fold_left_first(chocolate_squares.begin(), chocolate_squares.begin() + month, plus{})};
    int ways_bar_can_be_divided{sum == day};

    for (int n{static_cast<int>(chocolate_squares.size())}; auto i : views::iota(month, n)) {
        sum += chocolate_squares[i] - chocolate_squares[i - month];
        if (sum == day)
            ++ways_bar_can_be_divided;
    }

    return ways_bar_can_be_divided;
}
