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

// T: O(nQueries)
// S: O(1) extra space
func printQueries(arr []int, nRotation, nQueries int) {
    n := len(arr)
    offset := n - nRotation % n
    for range nQueries {
        var query int
        _, _ = fmt.Scan(&query)
        idx := (query + offset) % n
        fmt.Println(arr[idx])
    }
}
