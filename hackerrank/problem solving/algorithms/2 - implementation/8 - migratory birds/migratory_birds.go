// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    birdsToCounts := counter(n)
    fmt.Println(findMostSpottedBird(birdsToCounts))
}

// n: length of input
// k: length of distinct numbers
// T: O(n)
// S: O(k) = O(n) extra space
func counter(n int) map[int]int {
    freqMap := map[int]int{}
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        freqMap[x]++
    }
    return freqMap
}

// n: length of input
// k: length of hash birds_to_counts
// T: O(k) = O(n)
// S: O(1) extra space
func findMostSpottedBird(birdsToCounts map[int]int) int {
    var resBird, resCount int
    for bird, count := range birdsToCounts {
        if count > resCount || (count == resCount && bird < resBird) {
            resBird, resCount = bird, count
        }
    }
    return resBird
}
