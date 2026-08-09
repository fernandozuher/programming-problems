// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    birdsToCounts := readInput()
    fmt.Println(findMostSpottedBird(birdsToCounts))
}

// n: length of input
// T: O(n)
// S: O(n) extra space
func readInput() map[int]int {
    morfoio.SkipInputLn()

    freqMap := map[int]int{}
    for _, x := range morfoio.ReadLn[int]() {
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
