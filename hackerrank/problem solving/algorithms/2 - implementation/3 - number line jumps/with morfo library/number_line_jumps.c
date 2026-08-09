// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// C23

#include <stdio.h>
#include "morfo/io.h"

typedef struct {
    int x1, v1, x2, v2;
} state;

state read_input();
bool kangaroo(const state *s);

int main()
{
    state initial_state = read_input();
    puts(kangaroo(&initial_state) ? "YES" : "NO");
    return 0;
}

state read_input()
{
    state s;
    s.x1 = morfo_read(int);
    s.v1 = morfo_read(int);
    s.x2 = morfo_read(int);
    s.v2 = morfo_read(int);
    return s;
}

// T: O(1)
// S: O(1) extra space
bool kangaroo(const state *s)
{
    if (s->v1 == s->v2)
        return s->x1 == s->x2;

    int distance_diff = s->x2 - s->x1;
    int velocity_diff = s->v1 - s->v2;
    return distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0;
}
