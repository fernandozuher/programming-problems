// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var size int = ReadANumber()
    var array []int = ReadAnArray(size)
    sort.Ints(array)

    var result []int = CutTheSticks(array)
    PrintArray(result)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func ReadAnArray(size int) []int {
        var array []int = make([]int, size)
        for i, _ := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func CutTheSticks(array []int) []int {
        var size int = len(array)
        var remainingSticksOfEachIteration []int = InitializeResult(size)
        
        for i := 0; i < size; {
            var shortestStickLength int = array[i]

            i = FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array)
            var currentIterationSize int = size - i
            if i == size {
                break
            }

            remainingSticksOfEachIteration = append(remainingSticksOfEachIteration, currentIterationSize)
            DecreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, shortestStickLength)
        }

        return remainingSticksOfEachIteration
    }

        func InitializeResult(size int) []int {
            var remainingSticksOfEachIteration []int = make([]int, 1)
            remainingSticksOfEachIteration[0] = size
            return remainingSticksOfEachIteration
        }

        func FindFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index int, array []int) int {
            var size int = len(array)
            var shortestStickLength int = array[index]
            for index < size && array[index] == shortestStickLength {
                index++
            }
            return index
        }

        func DecreaseSticksLengthsHigherThanCurrentShortestStickLength(index int, array []int, shortestStickLength int) {
            for i := index; i < len(array); i++ {
                array[i] -= shortestStickLength
            }
        }

    func PrintArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
