// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <iostream>

using namespace std;

int save_the_prisoner(int prisoners, int sweets, int start_chair);

// n = test cases
// T = O(n)
// S = O(1)
int main()
{
    int n;
    cin >> n;

    for (int i{}; i < n; ++i) {
        int prisoners, sweets, start_chair;
        cin >> prisoners >> sweets >> start_chair;
        cout << save_the_prisoner(prisoners, sweets, start_chair) << '\n';
    }
}

// T = O(1)
// S = O(1)
int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
