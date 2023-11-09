// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var a, b int
    fmt.Scan(&a, &b)
    fmt.Println(solveMeFirst(a, b))
}

    func solveMeFirst(a int, b int) int {
        return a + b
    }
