// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var testCases []int = readLines(n)
    printArray(utopianTree(testCases))
}

    func readLines(n int) []int {
        var array []int = make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func utopianTree(testCases []int) []int {
        var treesHeights []int = make([]int, len(testCases))
        for i := range treesHeights {
            treesHeights[i] = calculateHeight(testCases[i])
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

    func printArray(array []int) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
