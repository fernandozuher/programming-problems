// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int number)
    {
        string binary = _convertIntToBinaryString(number);
        int longestBinaryGap = _findLongestBinaryGap(ref binary);
        return longestBinaryGap;
    }

        private string _convertIntToBinaryString(int number)
        {
            return Convert.ToString(number, 2);
        }

        private int _findLongestBinaryGap(ref string binary)
        {
            int longestBinaryGap = 0;

            for (List<int> index = new List<int>(new int[3]); !index.Contains(-1);)
            {
                int gapLength = _findGapLength(ref binary, ref index);
                longestBinaryGap = Math.Max(gapLength, longestBinaryGap);
            }

            return longestBinaryGap;
        }

            private int _findGapLength(ref string binary, ref List<int> index)
            {
                index[0] = binary.IndexOf('1', index[1]);
                if (index[0] != -1)
                {
                    index[1] = binary.IndexOf('0', index[0] + 1);
                    if (index[1] != -1)
                    {
                        index[2] = binary.IndexOf('1', index[1] + 1);
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
