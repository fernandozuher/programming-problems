// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

class Solution
{
    public int solution(int[] array)
    {
        int passingCarsPairs = 0;

        for (int i = 0, east = 0, west, passingCarsLimit = 1000000000; i < array.Length; i++)
            if ((west = array[i]) == 1)
            {
                if ((passingCarsPairs += east) > passingCarsLimit)
                    return -1;
            } else
                east++;

        return passingCarsPairs;
    }
}
