// Source: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/
package solution

func Solution(endPosition int, array []int) int {
    var arraySize int = len(array)

    if endPosition > arraySize {
        return -1
    }

    var visited_positions []bool = make([]bool, endPosition+1)
    var visitedPositionsCounter int = 0
    var i int

    for i = 0; i < arraySize && visitedPositionsCounter < endPosition; i++ {
        var position int = array[i]
        var hasThatPositionBeenVisited bool = visited_positions[position]

        if !hasThatPositionBeenVisited {
            visited_positions[position] = true
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
