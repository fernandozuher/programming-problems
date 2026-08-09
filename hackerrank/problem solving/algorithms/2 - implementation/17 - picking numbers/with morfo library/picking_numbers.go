// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfocollections"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int]()
    fmt.Println(pickingNumbers(morfocollections.Counter(arr)))
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
