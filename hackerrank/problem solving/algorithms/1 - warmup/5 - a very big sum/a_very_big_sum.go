// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(aVeryBigSum(n))
}

// T: O(n)
// S: O(1) extra space
func aVeryBigSum(n int) int64 {
    var sum int64 = 0
    for range n {
        var x int64
        _, _ = fmt.Scan(&x)
        sum += x
    }
    return sum
}
