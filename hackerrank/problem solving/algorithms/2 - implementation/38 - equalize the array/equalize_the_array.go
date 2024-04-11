// https//www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    var frequency map[int]int = readArrayIntoMap(n)
    fmt.Println(equalizeArray(frequency, n))
}

    func readArrayIntoMap(n int) map[int]int {
        arrayMap := make(map[int]int)
        for ; n > 0; n-- {
            var x int
            fmt.Scanf("%d", &x)
            arrayMap[x]++
        }
        return arrayMap
    }

    func equalizeArray(arrayMap map[int]int, n int) int {
        var maximumQuantityOfEqualElement int = maxValue(arrayMap)
        var minimumNumberRequiredDeletions int = n - maximumQuantityOfEqualElement
        return minimumNumberRequiredDeletions
    }

        func maxValue(arrayMap map[int]int) int {
            max := math.MinInt
            for _, v := range arrayMap {
                if v > max {
                    max = v
                }
            }
            return max
        }
