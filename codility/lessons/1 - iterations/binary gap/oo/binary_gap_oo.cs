// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int number)
    {
        BinaryGap obj = new BinaryGap(number);
        return obj.GetLongestBinaryGap();
    }
}

    public class BinaryGap
    {
        private int _number;
        private string _binary;
        private int _longestBinaryGap;

        public BinaryGap(int number)
        {
            _number = number;
            _binary = "";
            _longestBinaryGap = 0;

            _binary = _convertIntToBinaryString(_number);
            _findLongestBinaryGap();
        }

            private string _convertIntToBinaryString(int number)
            {
                return Convert.ToString(number, 2);
            }

            private void _findLongestBinaryGap()
            {
                for (List<int> index = new List<int>(new int[3]); !index.Contains(-1);)
                {
                    int gapLength = _findGapLength(ref index);
                    _longestBinaryGap = Math.Max(gapLength, _longestBinaryGap);
                }
            }

                private int _findGapLength(ref List<int> index)
                {
                    index[0] = _binary.IndexOf('1', index[1]);
                    if (index[0] != -1)
                    {
                        index[1] = _binary.IndexOf('0', index[0] + 1);
                        if (index[1] != -1)
                        {
                            index[2] = _binary.IndexOf('1', index[1] + 1);
                            if (index[2] != -1)
                            {
                                int gapLength = index[2] - index[1];
                                return gapLength;
                            }
                            else
                                return 0;
                        }
                        else
                            return 0;
                    }
                    else
                        return 0;
                }

        public int GetLongestBinaryGap()
        {
            return _longestBinaryGap;
        }
    }
