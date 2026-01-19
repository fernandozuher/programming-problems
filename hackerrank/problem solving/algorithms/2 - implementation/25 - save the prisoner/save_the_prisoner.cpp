// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int save_the_prisoner(int prisoners, int sweets, int start_chair);

int main()
{
    int n;
    cin >> n;
    for (int i{}; i < n; ++i) {
        int prisoners, sweets, start_chair;
        cin >> prisoners >> sweets >> start_chair;
        println("{}", save_the_prisoner(prisoners, sweets, start_chair));
    }
}

// T: O(1)
// S: O(1) extra space
int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
