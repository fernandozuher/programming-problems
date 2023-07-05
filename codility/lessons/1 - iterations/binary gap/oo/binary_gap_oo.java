// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

import java.util.List;
import java.util.Arrays;

public class Solution {
    public int solution(int number) {
        BinaryGap obj = new BinaryGap(number);
        return obj.getLongestBinaryGap();
    }
}

    class BinaryGap {
        private int _number;
        private String _binary;
        private int _longestBinaryGap;

        public BinaryGap(int number) {
            _number = number;
            _binary = "";
            _longestBinaryGap = 0;

            _binary = _convertIntToBinaryString(_number);
            _findLongestBinaryGap();
        }

            private String _convertIntToBinaryString(int number) {
                return Integer.toBinaryString(number);
            }

            private void _findLongestBinaryGap() {
                for (List<Integer> index = Arrays.asList(new Integer[] {0, 0, 0}); !index.contains(-1);) {
                    final int gap_length = _findGapLength(index);
                    _longestBinaryGap = Math.max(gap_length, _longestBinaryGap);
                }
            }

                private int _findGapLength(List<Integer> index) {
                    index.set(0, _binary.indexOf("1", index.get(1)));

                    if (index.get(0) != -1) {
                        index.set(1, _binary.indexOf("0", index.get(0) + 1));

                        if (index.get(1) != -1) {
                            index.set(2, _binary.indexOf("1", index.get(1) + 1));

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

        public int getLongestBinaryGap() {
            return _longestBinaryGap;
        }
    }
