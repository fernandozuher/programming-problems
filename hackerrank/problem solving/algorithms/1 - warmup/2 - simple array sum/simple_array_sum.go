// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Print(sumStdin(n))
}

func sumStdin(n int) int {
    sum := 0
    for range n {
        var x int
        fmt.Scan(&x)
        sum += x
    }
    return sum
}
