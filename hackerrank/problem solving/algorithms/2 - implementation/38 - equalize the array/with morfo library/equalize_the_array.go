// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfocollections"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int]()
    fmt.Println(minDeletionsToEqualize(arr))
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
func minDeletionsToEqualize(arr []int) int {
    maxCount := 0
    for _, count := range morfocollections.Counter(arr) {
        if count > maxCount {
            maxCount = count
        }
    }
    return len(arr) - maxCount
}
