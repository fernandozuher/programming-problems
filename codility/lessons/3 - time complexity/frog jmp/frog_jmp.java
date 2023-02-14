// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

import java.lang.Math;

class Solution {
    public int solution(int currentPosition, int destination, int jumpDistance) {
        final float numberOfJumps = (float)(destination - currentPosition) / jumpDistance;
        final int minimumNumberOfJumps = (int) Math.ceil(numberOfJumps);
        return minimumNumberOfJumps;
    }
}
