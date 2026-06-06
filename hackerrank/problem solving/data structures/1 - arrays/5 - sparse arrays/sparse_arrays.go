// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    strings := readLines(n)
    stringsToCounts := counter(strings)

    _, _ = fmt.Scan(&n)
    queries := readLines(n)

    for _, x := range countsFrom(stringsToCounts, queries) {
        fmt.Println(x)
    }
}

func readLines(n int) []string {
    arr := make([]string, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func counter(arr []string) map[string]int {
    freqMap := map[string]int{}
    for _, x := range arr {
        freqMap[x]++
    }
    return freqMap
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
func countsFrom(freqMap map[string]int, queries []string) []int {
    arr := make([]int, len(queries))
    for i, q := range queries {
        arr[i] = freqMap[q]
    }
    return arr
}
