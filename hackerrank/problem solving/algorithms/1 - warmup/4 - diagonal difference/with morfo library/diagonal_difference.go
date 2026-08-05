// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int]()
    fmt.Println(diagonalDifference(n))
}

// T: O(n^2)
// S: O(n) extra space
func diagonalDifference(n int) int {
    primarySum, secondarySum := 0, 0

    for i := range n {
        arr := morfoio.ReadLn[int]()
        primarySum += arr[i]
        secondarySum += arr[n-i-1]
    }

    return int(math.Abs(float64(secondarySum - primarySum)))
}
