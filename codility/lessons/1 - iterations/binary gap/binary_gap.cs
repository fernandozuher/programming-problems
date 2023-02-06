// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

using System;
using System.Collections.Generic;


class Solution
{
    private string _binary;
    private int _longestBinaryGap;

    public int solution(int NUMBER)
    {
        _binary = _ConvertIntToBinaryString(NUMBER);
        _longestBinaryGap = _FindLongestBinaryGap();
        return _longestBinaryGap;
    }

        private string _ConvertIntToBinaryString(int NUMBER)
        {
            string binary = Convert.ToString(NUMBER, 2);
            return binary;
        }

        private int _FindLongestBinaryGap()
        {
            int longestBinaryGap = 0;

            for (List<int> index = new List<int>(new int[3]); !index.Contains(-1);)
            {
                int gapLength = _FindGapLength(index);
                longestBinaryGap = Math.Max(gapLength, longestBinaryGap);
            }

            return longestBinaryGap;
        }

            private int _FindGapLength(List<int> index)
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
}
