

class Solution {
    public int solution(int N) {
        final String BINARY = Integer.toBinaryString(N);
        int i = 0, j = 0, max_gap = 0;
        while ((i = BINARY.indexOf('1', j)) >= 0 && (j = BINARY.indexOf('1', i+1)) > 0)
            max_gap = Math.max(j - i - 1, max_gap);
        return max_gap;
    }
}