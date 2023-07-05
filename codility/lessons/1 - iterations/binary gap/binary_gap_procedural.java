// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

import java.util.List;
import java.util.Arrays;

public class Solution {
    public int solution(int number) {
        final String binary = _convertIntToBinaryString(number);
        final int longestBinaryGap = _findLongestBinaryGap(binary);
        return longestBinaryGap;
    }

        private String _convertIntToBinaryString(int number) {
            return Integer.toBinaryString(number);
        }

        private int _findLongestBinaryGap(String binary) {
            int longestBinaryGap = 0;

            for (List<Integer> index = Arrays.asList(new Integer[]{0, 0, 0}); !index.contains(-1);) {
                final int gap_length = _findGapLength(binary, index);
                longestBinaryGap = Math.max(gap_length, longestBinaryGap);
            }

            return longestBinaryGap;
        }

            private int _findGapLength(String binary, List<Integer> index) {
                index.set(0, binary.indexOf("1", index.get(1)));

                if (index.get(0) != -1) {
                    index.set(1, binary.indexOf("0", index.get(0) + 1));

                    if (index.get(1) != -1) {
                        index.set(2, binary.indexOf("1", index.get(1) + 1));

                        if (index.get(2) != -1) {
                            final int gap_length = index.get(2) - index.get(1);
                            return gap_length;
                        } else
                            return 0;
                    } else
                        return 0;
                } else
                    return 0;
            }
}
