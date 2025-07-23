// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n, maxJump int
    fmt.Scan(&n, &maxJump)
    hurdles := readNumbers(n)
    fmt.Println(hurdleRace(hurdles, maxJump))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func hurdleRace(hurdles []int, maxJump int) int {
    return max(0, slices.Max(hurdles) - maxJump)
}
