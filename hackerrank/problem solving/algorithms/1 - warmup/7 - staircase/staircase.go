// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    staircase(n)
}

// T: O(n^2)
// S: O(n) extra space
func staircase(n int) {
    for i := 1; i <= n; i++ {
        spaces := strings.Repeat(" ", n-i)
        hashes := strings.Repeat("#", i)
        fmt.Println(spaces + hashes)
    }
}
