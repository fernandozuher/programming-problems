// Source: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

class Solution {
    public int solution(int begin, int end, int divisor) {
        int dividend = (end - begin) / divisor;

        if (begin % divisor == 0 || end % divisor == 0
                || (begin < divisor && (end % divisor + divisor - begin) < divisor))
            dividend++;

        return dividend;
    }
}
