// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n, rotateBy int
    _, _ = fmt.Scan(&n, &rotateBy)
    arr := readNumbers(n)
    rotate(arr, rotateBy)
    for _, x := range arr {
        fmt.Print(x, " ")
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func rotate(arr []int, rotateBy int) {
    if rotateBy >= len(arr) {
        rotateBy %= len(arr)
    }
    slices.Reverse(arr[:rotateBy])
    slices.Reverse(arr[rotateBy:])
    slices.Reverse(arr)
}
