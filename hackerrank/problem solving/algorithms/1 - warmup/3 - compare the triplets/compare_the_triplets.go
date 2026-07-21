// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const N = 3
    tripletA := readNums(N)
    tripletB := readNums(N)
    scoreA, scoreB := compareTriplets(tripletA, tripletB)
    fmt.Println(scoreA, scoreB)
}

func readNums(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
func compareTriplets(tripletA, tripletB []int) (int, int) {
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
