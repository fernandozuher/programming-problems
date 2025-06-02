// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
bool kangaroo(const int positions_and_velocities[]);

int main()
{
    constexpr int n = 4;
    int positions_and_velocities[n];
    read_numbers(positions_and_velocities, n);
    puts(kangaroo(positions_and_velocities) ? "YES" : "NO");
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

bool kangaroo(const int positions_and_velocities[])
{
    int x1 = positions_and_velocities[0];
    int v1 = positions_and_velocities[1];
    int x2 = positions_and_velocities[2];
    int v2 = positions_and_velocities[3];

    if (v1 == v2)
        return x1 == x2;

    int distance_diff = x2 - x1;
    int velocity_diff = v1 - v2;
    return distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0;
}
