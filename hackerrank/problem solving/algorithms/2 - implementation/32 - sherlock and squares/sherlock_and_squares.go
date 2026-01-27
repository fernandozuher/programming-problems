// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    for range n {
        var a, b int
        _, _ = fmt.Scan(&a, &b)
        fmt.Println(squares(a, b))
    }
}

// T: O(1)
// S: O(1) extra space
func squares(startNum, endNum int) int {
    maxSquare := int(math.Floor(math.Sqrt(float64(endNum))))
    minSquare := int(math.Ceil(math.Sqrt(float64(startNum))))
    return maxSquare - minSquare + 1
}
