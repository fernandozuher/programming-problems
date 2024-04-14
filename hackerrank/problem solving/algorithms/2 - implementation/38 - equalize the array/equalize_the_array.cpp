// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

import <algorithm>;
import <iostream>;
import <map>;
import <ranges>;

using namespace std;

int equalize_array(const map<int, int>& frequency, const int n);

int main()
{
    int n;
    cin >> n;
    map<int, int> frequency;
    for (int i{}, x; i < n && cin >> x; ++frequency[x], ++i);
    cout << equalize_array(frequency, n) << '\n';

    return 0;
}

    int equalize_array(const map<int, int>& array, const int n)
    {
        int maximum_quantity_of_equal_element {*ranges::max_element(views::values(array))};
        int minimum_number_required_deletions {n - maximum_quantity_of_equal_element};
        return minimum_number_required_deletions;
    }
