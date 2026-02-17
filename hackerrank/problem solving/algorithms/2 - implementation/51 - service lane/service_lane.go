// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n, t int
    _, _ = fmt.Scan(&n, &t)
    widths := readNumbers(n)
    for range t {
        fmt.Println(minWidthInSegment(widths, readNumbers(2)))
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array widths
// T: O(n)
// S: O(1) extra space
func minWidthInSegment(widths, segment []int) int {
    return slices.Min(widths[segment[0] : segment[1]+1])
}
