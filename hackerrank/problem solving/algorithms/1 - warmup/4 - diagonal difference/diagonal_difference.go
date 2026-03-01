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

func diagonalDifference(n int) int {
    primarySum, secondarySum := 0, 0

    for i := range n {
        arr := readNumbers(n)
        primarySum += arr[i]
        secondarySum += arr[n-i-1]
    }

    return int(math.Abs(float64(secondarySum - primarySum)))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}
