// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

const NO_INDEX int = -1

func main() {
    var arraySize int
    fmt.Scan(&arraySize)
    fmt.Println(findMinimumDistanceWhileReadElements(arraySize))
}

func findMinimumDistanceWhileReadElements(size int) int {
    var minimumDistance int = math.MaxInt
    var firstIndexesOfElements map[int][2]int = make(map[int][2]int)

    for i, element := 0, 0; i < size; i++ {
        fmt.Scan(&element)

        if indexes, ok := firstIndexesOfElements[element]; ok {
            var firstIndex, secondIndex int = indexes[0], indexes[1]

            if secondIndex == NO_INDEX {
                secondIndex = i
                indexes[1] = secondIndex
                var minimumDistanceOfCurrentElement int = secondIndex - firstIndex
                minimumDistance = min(minimumDistance, minimumDistanceOfCurrentElement)
            }
        } else {
            firstIndexesOfElements[element] = [2]int{i, NO_INDEX}
        }
    }

    return minimumDistanceOrNoIndex(minimumDistance)
}

func min(num1 int, num2 int) int {
    if num1 <= num2 {
        return num1
    }
    return num2
}

func minimumDistanceOrNoIndex(minimumDistance int) int {
    if minimumDistance != math.MaxInt {
        return minimumDistance
    }
    return NO_INDEX
}
