// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int]()
    fmt.Println(minDistance(arr))
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
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
