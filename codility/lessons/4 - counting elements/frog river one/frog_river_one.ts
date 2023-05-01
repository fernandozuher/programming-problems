// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

function solution(endPosition: number, array: number[]) {
    const ARRAY_SIZE: number = array.length;

    if (endPosition > ARRAY_SIZE)
        return -1;

    let visitedPositions: Array<boolean> = Array(endPosition + 1).fill(false);
    let visitedPositionsCounter: number = 0;
    let i: number;

    for (i = 0; i < ARRAY_SIZE && visitedPositionsCounter < endPosition; i++) {
        const POSITION: number = array[i];
        const HAS_THAT_POSITION_BEEN_VISITED: boolean = visitedPositions[POSITION];

        if (!HAS_THAT_POSITION_BEEN_VISITED) {
            visitedPositions[POSITION] = true;
            visitedPositionsCounter++;
        }
    }

    const TIME_SPENT_JUMPING_ON_LEAFS: number = i - 1;

    return visitedPositionsCounter == endPosition ? TIME_SPENT_JUMPING_ON_LEAFS : -1;
}
