// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    sort.Ints(arr)
    for _, x := range cutTheSticks(arr) {
        fmt.Println(x)
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func cutTheSticks(arr []int) []int {
    res := []int{}
    for i, n := 0, len(arr); i < n; {
        res = append(res, n-i)
        for shortest := arr[i]; i < n && arr[i] == shortest; i++ {}
    }
    return res
}
