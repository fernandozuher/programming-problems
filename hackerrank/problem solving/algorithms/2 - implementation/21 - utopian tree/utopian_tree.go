// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    for _, x := range utopianTree(readNumbers(n)) {
        fmt.Println(x)
    }
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func utopianTree(testCases []int) []int {
    treesHeights := make([]int, len(testCases))
    for i := range treesHeights {
        treesHeights[i] = calculateHeight(testCases[i])
    }
    return treesHeights
}

func calculateHeight(cycles int) int {
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
