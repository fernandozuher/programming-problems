// https//www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(minDeletionsToEqualize(readNumbers(n)))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr, 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(n) = O(100) = O(1) extra space
func minDeletionsToEqualize(arr []int) int {
    maxCount := 0
    for _, count := range counter(arr) {
        if count > maxCount {
            maxCount = count
        }
    }
    return len(arr) - maxCount
}

func counter(arr []int) map[int]int {
    counter := make(map[int]int)
    for _, x := range arr {
        counter[x]++
    }
    return counter
}
