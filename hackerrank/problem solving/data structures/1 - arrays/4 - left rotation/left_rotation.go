// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, rotateBy int
    _, _ = fmt.Scan(&n, &rotateBy)

    if rotateBy > n-1 {
        rotateBy %= n
    }

    for i, x := range rotate(readNumbers(n), rotateBy) {
        if i > 0 {
            fmt.Print(" ")
        }
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

func rotate(array []int, n int) []int {
    return append(array[n:], array[:n]...)
}
