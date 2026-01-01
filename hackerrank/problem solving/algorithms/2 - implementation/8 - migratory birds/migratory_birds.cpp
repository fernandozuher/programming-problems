// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// C++23

import std;
using namespace std;

map<int, int> counter(int n);
int find_most_spotted_bird(const map<int, int>& bird_counts);

int main()
{
    int n;
    cin >> n;
    auto bird_counts{ counter(n) };
    cout << find_most_spotted_bird(bird_counts);
    return 0;
}

map<int, int> counter(int n)
{
    map<int, int> number_counts;
    for (int bird; n-- && cin >> bird; ++number_counts[bird]);
    return number_counts;
}

int find_most_spotted_bird(const map<int, int>& bird_counts)
{
    return ranges::max_element(bird_counts, {}, &pair<const int, int>::second)->first;
}
