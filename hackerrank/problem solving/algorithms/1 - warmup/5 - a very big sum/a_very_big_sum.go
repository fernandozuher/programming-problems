// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true
// Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(aVeryBigSum(n))
}

func aVeryBigSum(n int) int64 {
    var sum int64 = 0
    for range n {
        var x int64
        fmt.Scan(&x)
        sum += x
    }
    return sum
}
