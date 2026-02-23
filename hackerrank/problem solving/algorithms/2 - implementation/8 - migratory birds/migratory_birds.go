// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    birdsToCounts := readInput()
    fmt.Println(findMostSpottedBird(birdsToCounts))
}

// n: length of input
// T: O(n)
// S: O(n) extra space
func readInput() map[int]int {
    var n int
    _, _ = fmt.Scan(&n)

    freqMap := map[int]int{}
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        freqMap[x]++
    }

    return freqMap
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
func findMostSpottedBird(birdsToCounts map[int]int) int {
    var resID, resCount int
    for id, count := range birdsToCounts {
        if count > resCount || (count == resCount && id < resID) {
            resID, resCount = id, count
        }
    }
    return resID
}
