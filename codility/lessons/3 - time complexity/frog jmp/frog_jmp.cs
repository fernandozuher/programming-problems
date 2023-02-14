// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

using System;

class Solution {
    public int solution(int currentPosition, int destination, int jumpDistance) {
        float numberOfJumps = (float)(destination - currentPosition) / jumpDistance;
        int minimumNumberOfJumps = (int) Math.Ceiling(numberOfJumps);
        return minimumNumberOfJumps;
    }
}
