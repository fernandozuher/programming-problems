// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    for i := range 10 {
        i += 1
        fmt.Printf("%d x %d = %d\n", n, i, n*i)
    }
}
