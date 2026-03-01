// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const tripletSize = 3
    tripletA := readNumbers(tripletSize)
    tripletB := readNumbers(tripletSize)
    scoreA, scoreB := compareTriplets(tripletA, tripletB)
    fmt.Println(scoreA, scoreB)
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// tripletSize: length of array a and b = 3
// T: O(3) = O(1)
// S: O(1) extra space
func compareTriplets(a, b []int) (int, int) {
    scoreA, scoreB := 0, 0

    for i := range a {
        if a[i] > b[i] {
            scoreA++
        } else if b[i] > a[i] {
            scoreB++
        }
    }

    return scoreA, scoreB
}
