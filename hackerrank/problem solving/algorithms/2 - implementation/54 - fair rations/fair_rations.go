// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    peopleLoafCounts := readNumbers(n)
    if minLoaves := minLoavesToSatisfyRules(peopleLoafCounts); minLoaves == -1 {
        fmt.Println("NO")
    } else {
        fmt.Println(minLoaves)
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array peopleLoafCounts
// T: O(n)
// S: O(1) extra space
func minLoavesToSatisfyRules(peopleLoafCounts []int) int {
    loavesGiven := 0
    counts := peopleLoafCounts[0]

    for _, x := range peopleLoafCounts[1:] {
        if isOdd(counts) {
            loavesGiven += 2
            counts = x + 1
        } else {
            counts = x
        }
    }

    if isOdd(counts) {
        return -1
    }
    return loavesGiven
}

func isOdd(n int) bool {
    return n % 2 == 1
}
