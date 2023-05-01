# Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

def solution(endPosition, array):
    ARRAY_SIZE = len(array)

    if endPosition > ARRAY_SIZE:
        return -1

    visitedPositions = [False] * (endPosition + 1)
    visitedPositionsCounter = 0
    i = 0

    while i < ARRAY_SIZE and visitedPositionsCounter < endPosition:
        POSITION = array[i]
        HAS_THAT_POSITION_BEEN_VISITED = visitedPositions[POSITION]

        if not HAS_THAT_POSITION_BEEN_VISITED:
            visitedPositions[POSITION] = True
            visitedPositionsCounter += 1

        i += 1

    TIME_SPENT_JUMPING_ON_LEAFS = i - 1

    return TIME_SPENT_JUMPING_ON_LEAFS if visitedPositionsCounter == endPosition else -1
