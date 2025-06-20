// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>

using namespace std;

int find_most_spotted_bird(int n);

int main()
{
    int n;
    cin >> n;
    cout << find_most_spotted_bird(n);
    return 0;
}

int find_most_spotted_bird(int n)
{
    map<int, int> bird_count;
    for (int bird; n-- && cin >> bird; ++bird_count[bird]);
    return ranges::max_element(bird_count, {}, &pair<const int, int>::second)->first;
}
