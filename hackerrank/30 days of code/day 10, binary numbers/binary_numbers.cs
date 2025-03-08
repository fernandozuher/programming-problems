// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

using static System.Console;

public class Solution
{
    public static void Main()
    {
        int n = int.Parse(ReadLine());
        var binary = new IntToBinary(n);
        WriteLine(binary.SizeWidestRangeBits1);
    }
}

class IntToBinary
{
    private readonly string _binary;
    private readonly int _sizeWidestRangeBits1;

    public IntToBinary(int n)
    {
        _binary = Convert.ToString(n, 2);
        _sizeWidestRangeBits1 = FindSizeWidestRangeBits1();
    }

    private int FindSizeWidestRangeBits1()
    {
        int sizeWidestRange = 0;
        for (int i = 0; i < _binary.Length; i++)
            if (_binary[i] == '1')
            {
                int sizeRange = FindSizeRangeBits1(i);
                sizeWidestRange = Math.Max(sizeRange, sizeWidestRange);
                i += sizeRange;
            }
        return sizeWidestRange;
    }

    private int FindSizeRangeBits1(int beginIndex)
    {
        int index = FindBit0(beginIndex);
        int size = index == -1 ? _binary.Length : index;
        size -= beginIndex;
        return size;
    }

    private int FindBit0(int beginIndex)
    {
        return _binary.IndexOf('0', beginIndex);
    }

    public int SizeWidestRangeBits1 => _sizeWidestRangeBits1;
}
