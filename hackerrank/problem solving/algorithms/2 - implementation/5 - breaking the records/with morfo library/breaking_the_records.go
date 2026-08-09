// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    fmt.Println(breakingRecords(morfoio.ReadLn[int]()))
}

// n: length of scores
// T: O(n)
// S: O(1) extra space
func breakingRecords(scores []int) (int, int) {
    mostPoints, leastPoints := scores[0], scores[0]
    mostRecordBreaks, leastRecordBreaks := 0, 0

    for _, score := range scores {
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
