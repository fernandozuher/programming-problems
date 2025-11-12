// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    for range n {
        var cycles int
        fmt.Scan(&cycles)
        fmt.Println(utopianTree(cycles))
    }
}

func utopianTree(cycles int) int {
    height := 1

    for cycle := 1; cycle <= cycles; cycle++ {
        if isCycleHappeningDuringSpring(cycle) {
            height = height * 2
        } else {
            height++
        }
    }

    return height
}

func isCycleHappeningDuringSpring(cycle int) bool {
    return cycle&1 == 1
}
