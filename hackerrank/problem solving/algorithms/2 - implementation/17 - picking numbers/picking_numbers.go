// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(pickingNumbers(counter(n)))
}

func counter(n int) map[int]int {
    frequency := make(map[int]int)
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        frequency[x]++
    }
    return frequency
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
func pickingNumbers(frequency map[int]int) int {
    maxLen := 0
    for num := range frequency {
        maxLen = max(maxLen, frequency[num]+frequency[num+1])
    }
    return maxLen
}
