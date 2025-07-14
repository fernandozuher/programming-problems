// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int picking_numbers(const vector<int>& numbers);

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers{read_numbers(n)};
    cout << picking_numbers(numbers);
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> numbers(n);
    for (auto& x : numbers)
        cin >> x;
    return numbers;
}

int picking_numbers(const vector<int>& numbers)
{
    unordered_map<int, int> counter;
    for (int num : numbers)
        ++counter[num];

    int max_len{};
    for (auto [num, count] : counter) {
        int current{count + (counter.contains(num + 1) ? counter[num + 1] : 0)};
        max_len = max(max_len, current);
    }

    return max_len;
}
