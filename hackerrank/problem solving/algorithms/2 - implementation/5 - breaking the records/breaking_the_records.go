// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    var breakingMostPointsRecords, breakingLeastPointsRecords int = breakingRecords(array)
    fmt.Print(breakingMostPointsRecords, breakingLeastPointsRecords)
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func breakingRecords(scores []int) (int, int) {
    mostPoints, breakingMostPointsRecords := scores[0], 0
    leastPoints, breakingLeastPointsRecords := scores[0], 0

    for _, score := range scores {
        if score > mostPoints {
            mostPoints = score
            breakingMostPointsRecords++
        } else if score < leastPoints {
            leastPoints = score
            breakingLeastPointsRecords++
        }
    }

    return breakingMostPointsRecords, breakingLeastPointsRecords
}
