// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#include <iostream>

using namespace std;

int how_many_chocolates_can_be_eaten(int money, int cost, int wrappers_needed);

int main()
{
    int n;
    cin >> n;

    for (int i{}; i < n; ++i) {
        int money, cost, wrappers_needed;
        cin >> money >> cost >> wrappers_needed;
        cout << how_many_chocolates_can_be_eaten(money, cost, wrappers_needed) << '\n';
    }

    return 0;
}

int how_many_chocolates_can_be_eaten(int money, int cost, int wrappers_needed)
{
    int chocolates{money / cost};

    for (int wrappers{chocolates}; wrappers >= wrappers_needed;) {
        int free_chocolates{wrappers / wrappers_needed};
        wrappers = wrappers % wrappers_needed + free_chocolates;
        chocolates += free_chocolates;
    }

    return chocolates;
}
