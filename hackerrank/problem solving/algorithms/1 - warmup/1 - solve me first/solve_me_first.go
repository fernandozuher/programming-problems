// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n1, n2 int
    _, _ = fmt.Scan(&n1, &n2)
    fmt.Println(solveMeFirst(n1, n2))
}

// T: O(1)
// S: O(1) extra space
func solveMeFirst(n1, n2 int) int {
    return n1 + n2
}
