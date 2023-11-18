// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    staircase(n)
}

    func staircase(n int) {
        for i := 1; i <= n; i++ {
            for j := 0; j < n-i; j++ {
                fmt.Print(" ")
            }
            for k := 0; k < i; k++ {
                fmt.Print("#")
            }
            fmt.Print("\n")
        }
    }
