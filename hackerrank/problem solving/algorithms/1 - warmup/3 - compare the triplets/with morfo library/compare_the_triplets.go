// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    const N = 3
    tripletA := morfoio.ReadN[int](N)
    tripletB := morfoio.ReadN[int](N)
    scoreA, scoreB := computeTripletScores(tripletA, tripletB)
    fmt.Println(scoreA, scoreB)
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
func computeTripletScores(tripletA, tripletB []int) (int, int) {
    scoreA, scoreB := 0, 0

    for i := range tripletA {
        if tripletA[i] > tripletB[i] {
            scoreA++
        } else if tripletB[i] > tripletA[i] {
            scoreB++
        }
    }

    return scoreA, scoreB
}
