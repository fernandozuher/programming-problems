// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n, maxJump int
    _, _ = fmt.Scan(&n, &maxJump)
    hurdles := readNumbers(n)
    fmt.Println(hurdleRace(hurdles, maxJump))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array hurdles
// T: O(n)
// S: O(1) extra space
func hurdleRace(hurdles []int, maxJump int) int {
    return max(0, slices.Max(hurdles) - maxJump)
}
