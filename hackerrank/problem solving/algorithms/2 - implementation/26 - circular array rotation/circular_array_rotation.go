// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, n_rotation, nQueries int
    _, _ = fmt.Scan(&n, &n_rotation, &nQueries)
    arr := readNumbers(n)
    queries := readNumbers(nQueries)

    r := n_rotation % n
    for _, q := range queries {
        index := q - r
        if index < 0 {
            index = n + index
        }
        fmt.Println(arr[index])
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}
