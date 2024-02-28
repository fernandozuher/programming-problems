// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    sort.Ints(array)

    var result []int = cutTheSticks(array)
    printArray(result)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func cutTheSticks(array []int) []int {
        var n int = len(array)
        remainingSticksOfEachIteration := []int{n}

        for i := 0; i < n; {
            var shortestStickLength int = array[i]

            i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array)
            var currentIterationSize int = n - i
            if i == n {
                break
            }

            remainingSticksOfEachIteration = append(remainingSticksOfEachIteration, currentIterationSize)
            decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, shortestStickLength)
        }

        return remainingSticksOfEachIteration
    }

        func findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index int, array []int) int {
            var n int = len(array)
            var shortestStickLength int = array[index]
            for index < n && array[index] == shortestStickLength {
                index++
            }
            return index
        }

        func decreaseSticksLengthsHigherThanCurrentShortestStickLength(index int, array []int, shortestStickLength int) {
            for i := index; i < len(array); i++ {
                array[i] -= shortestStickLength
            }
        }

    func printArray(array []int) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
