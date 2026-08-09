// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int]()
    utopianTree := generateHeightsUtopianTree()
    for range n {
        cycles := morfoio.Read[int]()
        fmt.Println(utopianTree[cycles])
    }
}

// k: length of output = 61
// T: O(k) = O(61) = O(1)
// S: O(61) = O(1) extra space
func generateHeightsUtopianTree() []int {
    const maxCycles = 60
    heights := make([]int, maxCycles+1)
    height := 0

    for cycle := range maxCycles + 1 {
        if isCycleHappeningDuringSpring(cycle) {
            height *= 2
        } else {
            height += 1
        }
        heights[cycle] = height
    }

    return heights
}

func isCycleHappeningDuringSpring(cycle int) bool {
    return cycle&1 == 1
}
