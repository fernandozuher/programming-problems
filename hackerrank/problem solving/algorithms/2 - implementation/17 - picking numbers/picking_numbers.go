// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    sort.Ints(array)
    fmt.Println(pickingNumbers(array))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func pickingNumbers(numbers []int) int {
        var subarrayBiggestSize int = 0
        var firstReferenceNumberIndex int = 0
        var secondReferenceNumberIndex int = 0
        var subarrayCurrentSize int = 1

        for i, n := 1, len(numbers); i < n; i++ {
            var difference int = numbers[i] - numbers[firstReferenceNumberIndex]

            switch difference {
            case 0:
                subarrayCurrentSize++

            case 1:
                subarrayCurrentSize++
                if numbers[secondReferenceNumberIndex] != numbers[i] {
                    secondReferenceNumberIndex = i
                }

            default:
                subarrayBiggestSize = updateSubarrayBiggestSize(subarrayBiggestSize, subarrayCurrentSize)

                var update []int = updateFirstReferenceNumberIndexAndSubarrayCurrentSize(numbers, i, secondReferenceNumberIndex)

                firstReferenceNumberIndex = update[0]
                secondReferenceNumberIndex = i
                subarrayCurrentSize = update[1]
            }
        }

        return updateSubarrayBiggestSize(subarrayBiggestSize, subarrayCurrentSize)
    }

        func updateSubarrayBiggestSize(subarrayBiggestSize int, subarrayCurrentSize int) int {
            return int(math.Max(float64(subarrayBiggestSize), float64(subarrayCurrentSize)))
        }

        func updateFirstReferenceNumberIndexAndSubarrayCurrentSize(numbers []int, i int, secondReferenceNumberIndex int) []int {
            var firstReferenceNumberIndex, subarrayCurrentSize int

            if numbers[i]-numbers[secondReferenceNumberIndex] == 1 {
                firstReferenceNumberIndex = secondReferenceNumberIndex
                subarrayCurrentSize = i - secondReferenceNumberIndex + 1
            } else {
                firstReferenceNumberIndex = i
                subarrayCurrentSize = 1
            }

            return []int{firstReferenceNumberIndex, subarrayCurrentSize}
        }
