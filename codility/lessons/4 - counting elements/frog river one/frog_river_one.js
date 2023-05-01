// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

function solution(endPosition, array) {
    const ARRAY_SIZE = array.length;

    if (endPosition > ARRAY_SIZE)
        return -1;

    let visitedPositions = Array(endPosition + 1).fill();
    let visitedPositionsCounter = 0;
    let i;

    for (i = 0; i < ARRAY_SIZE && visitedPositionsCounter < endPosition; i++) {
        const POSITION = array[i];
        const HAS_THAT_POSITION_BEEN_VISITED = visitedPositions[POSITION];

        if (!HAS_THAT_POSITION_BEEN_VISITED) {
            visitedPositions[POSITION] = true;
            visitedPositionsCounter++;
        }
    }

    const TIME_SPENT_JUMPING_ON_LEAFS = i - 1;

    return visitedPositionsCounter == endPosition ? TIME_SPENT_JUMPING_ON_LEAFS : -1;
}
