// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var size int = ReadANumber()
    var array []int = ReadAnArray(size)

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
        sort.Ints(array)
        var size int = len(array)
        var remainingSticksInEachIteration []int = make([]int, 1)
        remainingSticksInEachIteration[0] = size

        for i := 0; i < size; {
            var shortestStickLength int = array[i]

            i = FindFirstElementIndexDifferentOfFirstCurrentshortestStickLengthIndex(i, array)
            var currentIterationSize int = size - i
            if i == size {
                break
            }

            remainingSticksInEachIteration = append(remainingSticksInEachIteration, currentIterationSize)
            DecreaseSticksLengthsHigherThanCurrentshortestStickLength(i, array, shortestStickLength)
        }

        return remainingSticksInEachIteration
    }

        func FindFirstElementIndexDifferentOfFirstCurrentshortestStickLengthIndex(index int, array []int) int {
            var size int = len(array)
            var shortestStickLength int = array[index]
            for index < size && array[index] == shortestStickLength {
                index++
            }
            return index
        }

        func DecreaseSticksLengthsHigherThanCurrentshortestStickLength(index int, array []int, shortestStickLength int) {
            for i := index; i < len(array); i++ {
                array[i] -= shortestStickLength
            }
        }

    func PrintArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
