// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    fmt.Println(minDistance(arr))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func minDistance(arr []int) int {
    lastSeen := map[int]int{}
    minDist := -1

    for i, x := range arr {
        if _, ok := lastSeen[x]; ok {
            dist := i - lastSeen[x]
            if minDist == -1 || dist < minDist {
                minDist = dist
                if minDist == 1 {
                    return 1
                }
            }
        }
        lastSeen[x] = i
    }

    return minDist
}
