using System;

class Result
{

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<int> arr)
    {
        int positiveQuantity = 0;
        int negativeQuantity = 0;
        int zeroQuantity = 0;

        foreach (var number in arr)
            if (number > 0)
                positiveQuantity++;
            else if (number < 0)
                negativeQuantity++;
            else
                zeroQuantity++;

        int n = arr.Count;
        float positiveValuesProportion = (float) positiveQuantity / n;
        float negativeValuesProportion = (float) negativeQuantity / n;
        float zeroValuesProportion = (float) zeroQuantity / n;

        Console.WriteLine("{0:0.000000}", positiveValuesProportion);
        Console.WriteLine("{0:0.000000}", negativeValuesProportion);
        Console.WriteLine("{0:0.000000}", zeroValuesProportion);
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());
        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();
        Result.plusMinus(arr);
    }
}
