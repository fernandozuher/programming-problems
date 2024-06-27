// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month);

int main()
{
    int n;
    cin >> n;
    vector chocolate_squares{read_int_array(n)};
    constexpr int n_day_month{2};
    vector day_month{read_int_array(n_day_month)};
    cout << birthday(chocolate_squares, day_month);
    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }

    int birthday(const vector<int>& chocolate_squares, const vector<int>& day_month)
    {
        int ways_bar_can_be_divided{};
        int day{day_month.front()};
        int month{day_month.back()};

        for (const int i : views::iota(0, static_cast<int>(chocolate_squares.size() - month + 1)))
            if (const int sum{*ranges::fold_left_first(chocolate_squares | views::drop(i) | views::take(month), plus())}; sum == day)
                ++ways_bar_can_be_divided;

        return ways_bar_can_be_divided;
    }
