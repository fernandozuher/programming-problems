// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import "fmt"

const (
    tripletSize = 3
    resultSize  = 2
)

func main() {
    tripletA := readInput()
    tripletB := readInput()
    result := compareTriplets(tripletA, tripletB)
    fmt.Printf("%d %d\n", result[0], result[1])
}

func readInput() [tripletSize]int {
    var array [tripletSize]int
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func compareTriplets(a [tripletSize]int, b [tripletSize]int) [resultSize]int {
    scoreA, scoreB := 0, 0

    for i := range a {
        if a[i] > b[i] {
            scoreA++
        } else if b[i] > a[i] {
            scoreB++
        }
    }

    return [resultSize]int{scoreA, scoreB}
}
