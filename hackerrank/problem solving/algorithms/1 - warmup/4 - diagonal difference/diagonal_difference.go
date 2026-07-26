// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(diagonalDifference(n))
}

// T: O(n^2)
// S: O(n) extra space
func diagonalDifference(n int) int {
    primarySum, secondarySum := 0, 0

    for i := range n {
        arr := readNums(n)
        primarySum += arr[i]
        secondarySum += arr[n-i-1]
    }

    return int(math.Abs(float64(secondarySum - primarySum)))
}

func readNums(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}
