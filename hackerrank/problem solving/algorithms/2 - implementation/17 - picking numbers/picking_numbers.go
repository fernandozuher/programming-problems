// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(pickingNumbers(counter(n)))
}

// n: length of initial input array of numbers
// k: length of freq_map
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
func counter(n int) map[int]int {
    freqMap := make(map[int]int)
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        freqMap[x]++
    }
    return freqMap
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
func pickingNumbers(freqMap map[int]int) int {
    maxLen := 0
    for num := range freqMap {
        maxLen = max(maxLen, freqMap[num]+freqMap[num+1])
    }
    return maxLen
}
