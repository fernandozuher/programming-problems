// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

using System.Collections.Generic;

class Solution {
    public int solution(int endPosition, int[] array) {
        int arraySize = array.Length;

        if (endPosition > arraySize)
            return -1;

        List<bool> visitedPositions = new List<bool>(new bool[endPosition + 1]);
        int visitedPositionsCounter = 0;
        int i;

        for (i = 0; i < arraySize && visitedPositionsCounter < endPosition; i++) {
            int position = array[i];
            bool hasThatPositionBeenVisited = visitedPositions[position];

            if (!hasThatPositionBeenVisited) {
                visitedPositions[position] = true;
                visitedPositionsCounter++;
            }
        }

        int timeSpentJumpingOnLeafs = i - 1;

        return visitedPositionsCounter == endPosition ? timeSpentJumpingOnLeafs : -1;
    }
}
