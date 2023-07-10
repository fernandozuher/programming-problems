// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

#include <cmath>

int solution(const int current_position, const int destination, const int jump_distance)
{
    return ceil((double)(destination - current_position) / jump_distance);
}
