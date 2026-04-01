// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, beautifulDifference int
    _, _ = fmt.Scan(&n, &beautifulDifference)
    arr := readNumbers(n)
    fmt.Println(findBeautifulTriplets(arr, beautifulDifference))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
func findBeautifulTriplets(arr []int, beautifulDifference int) int {
    values := make(map[int]bool)
    for _, v := range arr {
        values[v] = true
    }

    doubleBD := 2*beautifulDifference
    count := 0
    for _, x := range arr {
        if values[x+beautifulDifference] && values[x+doubleBD] {
            count++
        }
    }

    return count
}
