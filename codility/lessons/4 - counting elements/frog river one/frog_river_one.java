// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int solution(int endPosition, int[] array) {
        final int ARRAY_SIZE = array.length;

        if (endPosition > ARRAY_SIZE)
            return -1;

        List<Boolean> visitedPositions = new ArrayList<Boolean>(Collections.nCopies(endPosition + 1, false));
        int visitedPositionsCounter = 0;
        int i;

        for (i = 0; i < ARRAY_SIZE && visitedPositionsCounter < endPosition; i++) {
            final int POSITION = array[i];
            final boolean HAS_THAT_POSITION_BEEN_VISITED = visitedPositions.get(POSITION);

            if (!HAS_THAT_POSITION_BEEN_VISITED) {
                visitedPositions.set(POSITION, true);
                visitedPositionsCounter++;
            }
        }

        final int TIME_SPENT_JUMPING_ON_LEAFS = i - 1;

        return visitedPositionsCounter == endPosition ? TIME_SPENT_JUMPING_ON_LEAFS : -1;
    }
}
