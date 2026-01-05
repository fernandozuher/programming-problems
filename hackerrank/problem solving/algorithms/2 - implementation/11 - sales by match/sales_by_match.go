// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    sockCounts := counter(n)
    fmt.Println(sockMerchant(sockCounts))
}

func counter(n int) map[int]int {
    counter := map[int]int{}
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        counter[x]++
    }
    return counter
}

// n: quantity of entries in sockCounts
// T: O(n)
// S: O(1) extra space
func sockMerchant(sockCounts map[int]int) int {
    pairs := 0
    for _, count := range sockCounts {
        pairs += count / 2
    }
    return pairs
}
