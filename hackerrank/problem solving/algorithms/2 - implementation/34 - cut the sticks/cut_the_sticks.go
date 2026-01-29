// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    slices.Sort(arr)
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

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
func cutTheSticks(arr []int) []int {
    var res []int
    slow, n := 0, len(arr)

    for fast := range n {
        if arr[slow] == arr[fast] {
            continue
        }
        res = append(res, n-slow)
        slow = fast
    }

    res = append(res, n-slow)
    return res
}
