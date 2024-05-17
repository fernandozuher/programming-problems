// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    if minLoaves := findMinLoavesToSatisfyRules(n); minLoaves == -1 {
        fmt.Println("NO")
    } else {
        fmt.Println(minLoaves)
    }
}

func findMinLoavesToSatisfyRules(n int) int {
    minLoavesToSatisfyRules := 0
    var loaves int
    fmt.Scan(&loaves)

    for range n - 1 {
        if isOdd(loaves) {
            fmt.Scan(&loaves)
            loaves++
            minLoavesToSatisfyRules += 2
        } else {
            fmt.Scan(&loaves)
        }
    }

    if isOdd(loaves) {
        return -1
    } else {
        return minLoavesToSatisfyRules
    }
}

func isOdd(n int) bool {
    return n&1 == 1
}
