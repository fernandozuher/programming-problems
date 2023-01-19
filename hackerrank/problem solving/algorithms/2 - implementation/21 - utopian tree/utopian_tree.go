// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

package main

import (
    "fmt"
)


func main() {
    var nTestCases int = readLineAsInt()
    var nTestCasesCycles []int = readCycles(nTestCases)

    result := utopianTree(nTestCasesCycles)
    printTreesHeights(result)
}

    func readLineAsInt() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func readCycles(nTestCases int) []int {
        var nTestCasesCycles []int = make([]int, nTestCases)

        for i := range nTestCasesCycles {
            nTestCasesCycles[i] = readLineAsInt()
        }

        return nTestCasesCycles
    }

    func checkError(err error) {
        if err != nil {
            panic(err)
        }
    }

    func utopianTree(nTestCasesCycles []int) []int {
        var treesHeights []int = make([]int, len(nTestCasesCycles))

        for i := range treesHeights {
            treesHeights[i] = calculateHeight(nTestCasesCycles[i])
        }

        return treesHeights
    }

        func calculateHeight(cycles int) int {
            var height = 1

            for cycle := 1; cycle <= cycles; cycle++ {
                if isCycleHappeningDuringSpring(cycle) == true {
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

    func printTreesHeights(treesHeights []int) {
        for _, height := range treesHeights {
            fmt.Println(height)
        }
    }
