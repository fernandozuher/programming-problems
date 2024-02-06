// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, rotationCount, nQueries int
    fmt.Scan(&n, &rotationCount, &nQueries)
    var array []int = readIntArray(n)
    var queries []int = readIntArray(nQueries)

    rotationCount = reduceRotations(n, rotationCount)
    var rotatedArray []int = rotateArray(array, rotationCount)
    printArrayAccordingToIndexFromAnotherArray(rotatedArray, queries)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func reduceRotations(n int, rotationCount int) int {
        if n > 1 {
            if rotationCount >= n {
                return rotationCount % n
            } else {
                return rotationCount
            }
        } else {
            return 0
        }
    }

    func rotateArray(array []int, rotationCount int) []int {
        var firstPartNewArray []int = array[len(array)-rotationCount:]
        var secondPartNewArray []int = array[:len(array)-rotationCount]
        return append(firstPartNewArray, secondPartNewArray...)
    }

    func printArrayAccordingToIndexFromAnotherArray(array1 []int, array2 []int) {
        for _, i := range array2 {
            fmt.Println(array1[i])
        }
    }
