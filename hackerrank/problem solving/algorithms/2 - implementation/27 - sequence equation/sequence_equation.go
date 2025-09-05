// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    for _, val := range sequenceEquation(arr) {
        fmt.Println(val)
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func sequenceEquation(arr []int) []int {
    valuesToIndex := make([]int, len(arr))
    for i, val := range arr {
        valuesToIndex[val-1] = i
    }

    res := make([]int, len(arr))
    for i, val := range valuesToIndex {
        res[i] = valuesToIndex[val] + 1
    }

    return res
}
