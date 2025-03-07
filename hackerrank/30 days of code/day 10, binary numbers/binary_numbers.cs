// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        var binary = new IntToBinary(n);
        WriteLine(binary.MaxConsecutiveOnesFromBinary);
    }
}

class IntToBinary
{
    private readonly string _binary;
    private readonly int _maxConsecutiveOnes;

    public IntToBinary(int n)
    {
        _binary = Convert.ToString(n, 2);
        _maxConsecutiveOnes = FindMaxConsecutiveOnesFromBinary();
    }

    private int FindMaxConsecutiveOnesFromBinary()
    {
        int max1Bits = 0;
        for (int i = 0; i < _binary.Length; i++)
            if (_binary[i] == '1')
            {
                int nBits = SizeOfNextRangeOfBits1(i);
                max1Bits = Math.Max(nBits, max1Bits);
                i += nBits;
            }
        return max1Bits;
    }

    private int SizeOfNextRangeOfBits1(int beginIndex)
    {
        int nextAfterLastIndex = FindNextAfterLastIndexOfConsecutive1s(beginIndex);
        return nextAfterLastIndex - beginIndex;
    }

    private int FindNextAfterLastIndexOfConsecutive1s(int beginIndex)
    {
        int nextAfterLastIndex = _binary.IndexOf('0', beginIndex);
        return nextAfterLastIndex == -1 ? _binary.Length : nextAfterLastIndex;
    }

    public int MaxConsecutiveOnesFromBinary => _maxConsecutiveOnes;
}
