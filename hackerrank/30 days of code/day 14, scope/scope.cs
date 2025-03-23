// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

using static System.Console;

class Solution
{
    public static void Main()
    {
        ReadLine(); // Size not used
        List<int> numbers = [.. ReadLine().Split().Select(int.Parse)];
        var difference = new Difference(numbers);
        difference.ComputeDifference();
        WriteLine(difference.MaximumDifference);
    }
}

class Difference(List<int> elements)
{
    private readonly List<int> _elements = elements;
    public int MaximumDifference;

    public void ComputeDifference()
    {
        MaximumDifference = _elements.Max() - _elements.Min();
    }
}
