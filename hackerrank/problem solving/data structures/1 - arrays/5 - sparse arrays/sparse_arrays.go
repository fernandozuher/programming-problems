// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    inputStrings := counter(n)

    _, _ = fmt.Scan(&n)
    for _, x := range readQueriesAndCountMatches(inputStrings, n) {
        fmt.Println(x)
    }
}

func counter(n int) map[string]int {
    freqMap := map[string]int{}
    for range n {
        var line string
        _, _ = fmt.Scan(&line)
        freqMap[line] += 1
    }
    return freqMap
}

func readQueriesAndCountMatches(input map[string]int, n int) []int {
    result := make([]int, n)
    var query string
    for i := range n {
        _, _ = fmt.Scan(&query)
        result[i] = input[query]
    }
    return result
}
