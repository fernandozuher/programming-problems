// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(minimumNumberOfJumps(readNumbers(n)))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func minimumNumberOfJumps(clouds []int) int {
    jumps := 0
    for i, n := 0, len(clouds)-1; i < n; i += nextJump(i, clouds) {
        jumps++
    }
    return jumps
}

func nextJump(index int, clouds []int) int {
    if index+2 < len(clouds) {
        if isNextSecondCloudCumulus := clouds[index+2]; isNextSecondCloudCumulus == 0 {
            return 2
        }
    }
    return 1
}
