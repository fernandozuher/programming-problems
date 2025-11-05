// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> read_numbers_into_map(int n);
int picking_numbers(const unordered_map<int, int>& counter);

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << picking_numbers(read_numbers_into_map(n));
    return 0;
}

unordered_map<int, int> read_numbers_into_map(int n)
{
    unordered_map<int, int> counter;
    for (int i{}, num; i < n && cin >> num; ++i)
        ++counter[num];
    return counter;
}

int picking_numbers(const unordered_map<int, int>& counter)
{
    int max_len{};
    for (auto [num, count] : counter) {
        int current{count + (counter.contains(num + 1) ? counter.at(num + 1) : 0)};
        max_len = max(max_len, current);
    }
    return max_len;
}
