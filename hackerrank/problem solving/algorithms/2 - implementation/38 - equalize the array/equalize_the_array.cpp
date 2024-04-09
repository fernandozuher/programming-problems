// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <map>

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

    int equalize_array(const map<int, int>& frequency, const int n)
    {
        auto cmp {[](const auto& p1, const auto& p2) { return p1.second < p2.second;}};
        int maximum_quantity_of_equal_element {ranges::max_element(frequency, cmp)->second};
        int minimum_number_of_deletions_required {n - maximum_quantity_of_equal_element};
        return minimum_number_of_deletions_required;
    }
