// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

public class Solution
{
    public static void Main()
    {
        int[] line = ReadNumbers();
        int _ = line[0];
        int nPoints = line[1];
        int[] widths = ReadNumbers();

        for (int i = 0; i < nPoints; i++)
            Console.WriteLine(MaxAffordableWidthVehicleInRange(widths, ReadNumbers()));
    }

    private static int[] ReadNumbers()
    {
        return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
    }

    private static int MaxAffordableWidthVehicleInRange(int[] widths, int[] point)
    {
        int nElements = point[1] - point[0] + 1;
        return widths.Skip(point[0]).Take(nElements).Min();
    }
}
