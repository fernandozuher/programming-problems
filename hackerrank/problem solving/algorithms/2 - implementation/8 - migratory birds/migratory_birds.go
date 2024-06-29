// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    sort.Ints(array)
    fmt.Println(findMostSpottedBird(array))
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func findMostSpottedBird(birdSightings []int) int {
    var mostSpottedBird int = birdSightings[0]
    countMostSpottedBird := 1
    tempCountMostSpottedBird := 1
    n := len(birdSightings)

    for i := 1; i < n; i++ {
        if birdSightings[i] == birdSightings[i-1] {
            tempCountMostSpottedBird++
        } else if tempCountMostSpottedBird > countMostSpottedBird {
            mostSpottedBird = birdSightings[i-1]
            countMostSpottedBird = tempCountMostSpottedBird
            tempCountMostSpottedBird = 1
        }
    }

    if tempCountMostSpottedBird > countMostSpottedBird {
        mostSpottedBird = birdSightings[n-1]
    }

    return mostSpottedBird
}
