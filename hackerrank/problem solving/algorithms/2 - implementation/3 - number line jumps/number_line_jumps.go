// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

package main

import "fmt"

type State struct {
    x1, v1, x2, v2 int
}

func main() {
    initialState := readInput()
    if kangaroo(initialState) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func readInput() State {
    var s State
    _, _ = fmt.Scan(&s.x1, &s.v1, &s.x2, &s.v2)
    return s
}

// T: O(1)
// S: O(1) extra space
func kangaroo(s State) bool {
    if s.v1 == s.v2 {
        return s.x1 == s.x2
    }

    distanceDiff := s.x2 - s.x1
    velocityDiff := s.v1 - s.v2
    return distanceDiff*velocityDiff >= 0 && distanceDiff%velocityDiff == 0
}
