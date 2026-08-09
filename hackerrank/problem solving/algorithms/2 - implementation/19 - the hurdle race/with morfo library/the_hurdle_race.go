// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "slices"
)

func main() {
    morfoio.SkipInput()
    maxJump := morfoio.Read[int]()
    hurdles := morfoio.ReadLn[int]()
    fmt.Println(hurdleRace(hurdles, maxJump))
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
func hurdleRace(hurdles []int, maxJump int) int {
    return max(0, slices.Max(hurdles) - maxJump)
}
