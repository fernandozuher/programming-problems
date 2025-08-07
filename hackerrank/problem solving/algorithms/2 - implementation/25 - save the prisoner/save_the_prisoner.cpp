// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

int save_the_prisoner(int prisoners, int sweets, int start_chair);

int main()
{
    int n;
    cin >> n;
    vector<int> results(n);

    for (auto& x: results) {
        int prisoners, sweets, start_chair;
        cin >> prisoners >> sweets >> start_chair;
        x = save_the_prisoner(prisoners, sweets, start_chair);
    }

    for (auto x : results)
        cout << x << '\n';
}

int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
