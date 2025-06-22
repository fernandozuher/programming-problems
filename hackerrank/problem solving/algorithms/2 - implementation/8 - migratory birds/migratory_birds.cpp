// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>

using namespace std;

map<int, int> count_numbers_into_map(int n);
int find_most_spotted_bird(const map<int, int>& bird_count);

int main()
{
    int n;
    cin >> n;
    auto bird_count{count_numbers_into_map(n)};
    cout << find_most_spotted_bird(bird_count);
    return 0;
}

map<int, int> count_numbers_into_map(int n)
{
    map<int, int> birds;
    for (int bird; n-- && cin >> bird; ++birds[bird]);
    return birds;
}

int find_most_spotted_bird(const map<int, int>& bird_count)
{
    return ranges::max_element(bird_count, {}, &pair<const int, int>::second)->first;
}
