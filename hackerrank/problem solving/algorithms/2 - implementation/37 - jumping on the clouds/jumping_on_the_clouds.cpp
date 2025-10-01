// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int minimum_number_of_jumps(const vector<int>& clouds);
int next_jump(int index, const vector<int>& clouds);

int main()
{
    int n;
    cin >> n;
    cout << minimum_number_of_jumps(read_numbers(n));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int minimum_number_of_jumps(const vector<int>& clouds)
{
    int jumps{};
    for (int i{}, n = clouds.size() - 1; i < n; i += next_jump(i, clouds))
        ++jumps;
    return jumps;
}

int next_jump(int index, const vector<int>& clouds)
{
    if (index + 2 < clouds.size())
        if (bool is_next_second_cloud_cumulus{clouds[index + 2] == 0})
            return 2;
    return 1;
}
