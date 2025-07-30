// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(sockMerchant(readNumbersIntoMap(n)))
}

func readNumbersIntoMap(n int) map[int]int {
    counter := map[int]int{}
    for range n {
        var x int
        fmt.Scan(&x)
        counter[x]++
    }
    return counter
}

func sockMerchant(sockCounts map[int]int) int {
    pairs := 0
    for _, count := range sockCounts {
        pairs += count / 2
    }
    return pairs
}
