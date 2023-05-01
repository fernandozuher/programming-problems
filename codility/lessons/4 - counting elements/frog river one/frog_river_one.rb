# Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

def solution endPosition, array
    if endPosition > array.size
        return -1
    end

    visitedPositions = Array.new(endPosition + 1)
    visitedPositionsCounter = 0
    i = 0

    while i < array.size && visitedPositionsCounter < endPosition
        position = array[i]
        hasThatPositionBeenVisited = visitedPositions[position]

        if not hasThatPositionBeenVisited
            visitedPositions[position] = true
            visitedPositionsCounter += 1
        end

        i += 1
    end

    timeSpentJumpingOnLeafs = i - 1

    visitedPositionsCounter == endPosition ? timeSpentJumpingOnLeafs : -1
end
