// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var sizeArray int = ReadANumber()
    var array []int = ReadAnArray(sizeArray)

    var minimumNumberOfDeletionsRequired int = EqualizeArray(array)
    fmt.Println(minimumNumberOfDeletionsRequired)
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

    func EqualizeArray(array []int) int {
        sort.Ints(array)
        var maximumQuantityOfEqualElement int = FindMaximumQuantityOfEqualElement(array)
        var minimumNumberOfDeletionsRequired int = len(array) - maximumQuantityOfEqualElement
        return minimumNumberOfDeletionsRequired
    }

        func FindMaximumQuantityOfEqualElement(array []int) int {
            var maximumQuantityOfEqualElement int = 1

            for i, temporaryQuantityEqualElement, size := 1, 1, len(array); i < size; i++ {

                if AreConsecutiveElementesEqual(array[i-1], array[i]) {
                    temporaryQuantityEqualElement++
                    maximumQuantityOfEqualElement = int(math.Max(float64(temporaryQuantityEqualElement), float64(maximumQuantityOfEqualElement)))
                } else {
                    temporaryQuantityEqualElement = 1
                }
            }

            return maximumQuantityOfEqualElement
        }

            func AreConsecutiveElementesEqual(element1 int, element2 int) bool {
                return element1 == element2
            }
