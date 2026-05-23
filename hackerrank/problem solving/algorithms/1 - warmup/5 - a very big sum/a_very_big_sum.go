// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    fmt.Println(aVeryBigSum(arr))
}

func readNumbers(n int) []int64 {
    arr := make([]int64, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func aVeryBigSum(arr []int64) int64 {
    var sum int64 = 0
    for _, x := range arr {
        sum += x
    }
    return sum
}
