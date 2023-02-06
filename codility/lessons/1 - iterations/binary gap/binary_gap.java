// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

import java.util.*;


public class Solution {

    private String _binary;
    private int _longestBinaryGap;

    public int solution(int NUMBER) {
        _binary = _convertIntToBinaryString(NUMBER);
        _longestBinaryGap = _findLongestBinaryGap();
        return _longestBinaryGap;
    }

        private String _convertIntToBinaryString(int NUMBER) {
            return Integer.toBinaryString(NUMBER);
        }

        private int _findLongestBinaryGap() {
            int longestBinaryGap = 0;

            for (List<Integer> index = new ArrayList<Integer>(Arrays.asList(0, 0, 0)); !index.contains(-1);) {
                final int GAP_LENGTH = _findGapLength(index);
                longestBinaryGap = Math.max(GAP_LENGTH, longestBinaryGap);
            }

            return longestBinaryGap;
        }

            private int _findGapLength(List<Integer> index) {
                index.set(0, _binary.indexOf("1", index.get(1)));

                if (index.get(0) != -1) {
                    index.set(1, _binary.indexOf("0", index.get(0) + 1));

                    if (index.get(1) != -1) {
                        index.set(2, _binary.indexOf("1", index.get(1) + 1));

                        if (index.get(2) != -1) {
                            final int GAP_LENGTH = index.get(2) - index.get(1);
                            return GAP_LENGTH;
                        } else
                            return 0;
                    } else
                        return 0;
                } else
                    return 0;
            }
}
