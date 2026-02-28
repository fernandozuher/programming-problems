// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    socksToCounts := counter(n)
    fmt.Println(sockMerchant(socksToCounts))
}

// n: length of user input
// k: length of distinct numbers in user input
// k <= n
// T: O(n)
// S: O(k) extra space
func counter(n int) map[int]int {
    freqMap := map[int]int{}
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        freqMap[x]++
    }
    return freqMap
}

// n: length of initial user input
// k: length of entries in socksToCounts
// k <= n
// T: O(k)
// S: O(1) extra space
func sockMerchant(socksToCounts map[int]int) int {
    pairs := 0
    for _, x := range socksToCounts {
        pairs += x / 2
    }
    return pairs
}
