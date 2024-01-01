// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)

    var records [2]int = breakingRecords(array)
    fmt.Print(records[0], records[1])
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func breakingRecords(scores []int) [2]int {
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

        return [2]int{breakingMostPointsRecords, breakingLeastPointsRecords}
    }
