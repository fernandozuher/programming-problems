// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int solution(int endPosition, int[] array) {
        List<Boolean> visitedPositions = new ArrayList<Boolean>(Collections.nCopies(endPosition + 1, false));
        int visitedPositionsCounter = 0;
        int i;

        for (i = 0; i < array.length && visitedPositionsCounter < endPosition; i++) {
            final int position = array[i];
            final boolean hasThatPositionBeenVisited = visitedPositions.get(position);

            if (!hasThatPositionBeenVisited) {
                visitedPositions.set(position, true);
                visitedPositionsCounter++;
            }
        }

        final int timeSpentJumpingOnLeafs = i - 1;
        return visitedPositionsCounter == endPosition ? timeSpentJumpingOnLeafs : -1;
    }
}
