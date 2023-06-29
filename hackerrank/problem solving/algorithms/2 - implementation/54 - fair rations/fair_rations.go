// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

package main

import (
    "fmt"
    "strconv"
)

func main() {
    var nSubjects int
    fmt.Scan(&nSubjects)
    var nLoavesOfEachPerson []int = readAnIntArray(nSubjects)
    fmt.Println(findMinLoavesToSatisfyRules(nLoavesOfEachPerson))
}

    func readAnIntArray(size int) []int {
        var array []int = make([]int, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findMinLoavesToSatisfyRules(nLoavesOfEachPerson []int) string {
        var minLoavesToSatisfyRules int = 0
        var size int = len(nLoavesOfEachPerson)

        for i, newSize := 0, size-1; i < newSize; i++ {
            if nLoavesOfEachPerson[i] % 2 == 1 {
                nLoavesOfEachPerson[i]++
                nLoavesOfEachPerson[i+1]++
                minLoavesToSatisfyRules += 2
            }
        }

        if nLoavesOfEachPerson[size-1] % 2 == 1 {
            return "NO"
        }
        return strconv.Itoa(minLoavesToSatisfyRules)
    }
