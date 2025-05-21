// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// Go 1.22

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(diagonalDifference(n))
}

func diagonalDifference(n int) int {
    primarySum, secondarySum := 0, 0

    for i := range n {
        numbers := readNumbers(n)
        primarySum += numbers[i]
        secondarySum += numbers[n-i-1]

    }

    return int(math.Abs(float64(secondarySum - primarySum)))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}
