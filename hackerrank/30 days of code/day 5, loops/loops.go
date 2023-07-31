// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    for i := 1; i <= 10; i++ {
        fmt.Printf("%d x %d = %d\n", n, i, n*i)
    }
}
