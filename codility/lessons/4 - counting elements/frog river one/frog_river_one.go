// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

package solution

func Solution(endPosition int, array []int) int {
    visitedPositions := make([]bool, endPosition+1)
    visitedPositionsCounter := 0
    var i int

    for i = 0; i < len(array) && visitedPositionsCounter < endPosition; i++ {
        var position int = array[i]
        var hasThatPositionBeenVisited bool = visitedPositions[position]

        if !hasThatPositionBeenVisited {
            visitedPositions[position] = true
            visitedPositionsCounter++
        }
    }

    var timeSpentJumpingOnLeafs int = i - 1

    if visitedPositionsCounter == endPosition {
        return timeSpentJumpingOnLeafs
    } else {
        return -1
    }
}
