// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "slices"
)

func main() {
    n := morfoio.Read[int]()
    t := morfoio.Read[int]()
    widths := morfoio.ReadN[int](n)
    for range t {
        fmt.Println(minWidthInSegment(widths, morfoio.ReadLn[int]()))
    }
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
func minWidthInSegment(widths, segment []int) int {
    start, finish := segment[0], segment[1]
    return slices.Min(widths[start : finish + 1])
}
