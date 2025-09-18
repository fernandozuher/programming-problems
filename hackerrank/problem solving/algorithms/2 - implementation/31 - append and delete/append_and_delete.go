// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var initialString, finalString string
    var nOperations int
    _, _ = fmt.Scan(&initialString, &finalString, &nOperations)
    if appendAndDelete(initialString, finalString, nOperations) {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

func appendAndDelete(s1 string, s2 string, nOps int) bool {
    prefixLen := commonPrefixLength(s1, s2)
    totalOpsNeeded := (len(s1) - prefixLen) + (len(s2) - prefixLen)
    canRemoveAll := nOps >= len(s1)+len(s2)
    return canRemoveAll || (nOps >= totalOpsNeeded && (nOps-totalOpsNeeded)%2 == 0)
}

func commonPrefixLength(s1 string, s2 string) int {
    minLen := min(len(s1), len(s2))
    for i := range minLen {
        if s1[i] != s2[i] {
            return i
        }
    }
    return minLen
}
