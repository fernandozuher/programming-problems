// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class The_Birthday_Bar {

public:
    The_Birthday_Bar(const vector<int>& chocolate_squares, const vector<int>& day_month):
        chocolate_squares{chocolate_squares}, day{day_month.front()},
        month{day_month.back()}, n_divisions{}
    {
        birthday();
    }

    int ways_bar_can_be_divided() const
    {
        return n_divisions;
    }


private:
    vector<int> chocolate_squares;
    int day, month;
    int n_divisions;

    void birthday()
    {
        for (int i {}, n1 = chocolate_squares.size() - month + 1; i < n1; ++i) {
            int sum {};

            for (int j {i}, n2 {i + month}; j < n2; sum += chocolate_squares[j++]);
            if (sum == day)
                ++n_divisions;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> chocolate_squares {read_int_array(n)};

    const int n_day_month {2};
    vector<int> day_month {read_int_array(n_day_month)};

    The_Birthday_Bar obj{chocolate_squares, day_month};
    cout << obj.ways_bar_can_be_divided();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        generate(array.begin(), array.end(), [] {int x; cin >> x; return x;});
        return array;
    }
