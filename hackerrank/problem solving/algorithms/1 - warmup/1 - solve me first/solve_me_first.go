// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n1, n2 int
    fmt.Scan(&n1, &n2)
    fmt.Print(solveMeFirst(n1, n2))
}

func solveMeFirst(n1 int, n2 int) int {
    return n1 + n2
}
