// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

using System;

class Solution
{
    public int solution(int currentPosition, int destination, int jumpDistance)
    {
        return (int) Math.Ceiling((double)(destination - currentPosition) / jumpDistance);
    }
}
