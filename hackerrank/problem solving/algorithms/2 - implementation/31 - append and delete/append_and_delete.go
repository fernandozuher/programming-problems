// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var s1, s2 string
    var nOps int
    _, _ = fmt.Scan(&s1, &s2, &nOps)
    if appendAndDelete(s1, s2, nOps) {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
func appendAndDelete(s1, s2 string, nOps int) bool {
    prefixLen := commonPrefixLength(s1, s2)
    opsNeeded := (len(s1) - prefixLen) + (len(s2) - prefixLen)
    if nOps < opsNeeded {
        return false
    }

    if nOps >= len(s1)+len(s2) {
        return true
    }

    return (nOps-opsNeeded)%2 == 0
}

func commonPrefixLength(s1, s2 string) int {
    minLen := min(len(s1), len(s2))
    for i := range minLen {
        if s1[i] != s2[i] {
            return i
        }
    }
    return minLen
}
