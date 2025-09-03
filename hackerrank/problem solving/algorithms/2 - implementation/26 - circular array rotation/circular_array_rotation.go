// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, nRotation, nQueries int
    _, _ = fmt.Scan(&n, &nRotation, &nQueries)
    arr := readNumbers(n)
    queries := readNumbers(nQueries)
    printQueries(arr, queries, nRotation)
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func printQueries(arr, queries []int, nRotation int) {
    n := len(arr)
    r := nRotation % n
    for _, q := range queries {
        idx := (q + n - r) % n
        fmt.Println(arr[idx])
    }
}
