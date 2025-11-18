// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, nRotation, nQueries int
    _, _ = fmt.Scan(&n, &nRotation, &nQueries)
    arr := readNumbers(n)
    printQueries(arr, nRotation, nQueries)
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func printQueries(arr []int, nRotation, nQueries int) {
    n := len(arr)
    r := nRotation % n
    for range nQueries {
        var query int
        fmt.Scan(&query)
        idx := (query + n - r) % n
        fmt.Println(arr[idx])
    }
}
