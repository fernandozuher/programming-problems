// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(breakingRecords(readNumbers(n)))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func breakingRecords(scores []int) (int, int) {
    mostPoints, leastPoints := scores[0], scores[0]
    mostRecordBreaks, leastRecordBreaks := 0, 0

    for _, score := range scores[1:] {
        if score > mostPoints {
            mostPoints = score
            mostRecordBreaks++
        } else if score < leastPoints {
            leastPoints = score
            leastRecordBreaks++
        }
    }

    return mostRecordBreaks, leastRecordBreaks
}
