// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int save_the_prisoner(int prisoners, int sweets, int start_chair);

int main()
{
    int n = morfo::read();
    for (int i{}; i < n; ++i) {
        auto [prisoners, sweets, start_chair] = morfo::read<int, int, int>();
        println("{}", save_the_prisoner(prisoners, sweets, start_chair));
    }
}

// T: O(1)
// S: O(1) extra space
int save_the_prisoner(int prisoners, int sweets, int start_chair)
{
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1;
}
