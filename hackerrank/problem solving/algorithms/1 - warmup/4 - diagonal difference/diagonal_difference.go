// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
// From Go 1.22

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Print(diagonalDifference(n))
}

func diagonalDifference(n int) int {
    primaryDiagonal, secondaryDiagonal := 0, 0

    for i := range n {
        for j := range n {
            var x int
            fmt.Scan(&x)
            if i == j {
                primaryDiagonal += x
            }
            if j == n-i-1 {
                secondaryDiagonal += x
            }
        }
    }

    return int(math.Abs(float64(secondaryDiagonal - primaryDiagonal)))
}
