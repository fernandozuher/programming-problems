// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    slices.Reverse(arr)
    for _, x := arr {
        fmt.Print(x)
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}
