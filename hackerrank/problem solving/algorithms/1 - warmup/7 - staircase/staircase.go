// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    staircase(n)
}

func staircase(n int) {
    for i := range n {
        for range n - i + 1 {
            fmt.Print(" ")
        }
        for range i + 1 {
            fmt.Print("#")
        }
        fmt.Println("")
    }
}
