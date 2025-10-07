// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>

using namespace std;

map<int, int> counter(int n);
int equalize_array(const map<int, int>& counter, int n);

int main()
{
    int n;
    cin >> n;
    cout << equalize_array(counter(n), n) << '\n';
    return 0;
}

map<int, int> counter(int n)
{
    map<int, int> counter;
    for (int i{}, x; i < n && cin >> x; ++i)
        ++counter[x];
    return counter;
}

int equalize_array(const map<int, int>& counter, int n)
{
    int max_count{*ranges::max_element(views::values(counter))};
    return n - max_count;
}
