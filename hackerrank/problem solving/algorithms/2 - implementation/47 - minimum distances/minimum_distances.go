// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

const NoIndex int = -1

func main() {
    var n int
    _, err := fmt.Scan(&n)
    if err != nil {
        return
    }
    fmt.Println(findMinimumDistanceWhileReadElements(n))
}

func findMinimumDistanceWhileReadElements(n int) int {
    var minimumDistance = math.MaxInt
    firstIndexesOfElements := map[int][2]int{}

    for i := range n {
        var element int
        _, err := fmt.Scan(&element)
        if err != nil {
            return 0
        }

        if indexes, ok := firstIndexesOfElements[element]; ok {
            if firstIndex, secondIndex := indexes[0], indexes[1]; secondIndex == NoIndex {
                secondIndex = i
                indexes[1] = secondIndex
                minimumDistanceOfCurrentElement := secondIndex - firstIndex
                minimumDistance = min(minimumDistance, minimumDistanceOfCurrentElement)
            }
        } else {
            firstIndexesOfElements[element] = [2]int{i, NoIndex}
        }
    }

    return minimumDistanceOrNoIndex(minimumDistance)
}

func minimumDistanceOrNoIndex(minimumDistance int) int {
    if minimumDistance != math.MaxInt {
        return minimumDistance
    }
    return NoIndex
}
