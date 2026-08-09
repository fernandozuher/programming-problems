// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int]()
    nRotation := morfoio.Read[int]()
    nQueries := morfoio.Read[int]()
    arr := morfoio.ReadN[int](n)
    printQueries(arr, nRotation, nQueries)
}

// T: O(nQueries)
// S: O(1) extra space
func printQueries(arr []int, nRotation, nQueries int) {
    n := len(arr)
    offset := n - nRotation % n
    for range nQueries {
        query := morfoio.Read[int]()
        idx := (query + offset) % n
        fmt.Println(arr[idx])
    }
}
