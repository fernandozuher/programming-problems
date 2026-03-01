// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(sumStdin(n))
}

// T: O(n)
// S: O(1) extra space
func sumStdin(n int) int {
    sum := 0
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        sum += x
    }
    return sum
}
