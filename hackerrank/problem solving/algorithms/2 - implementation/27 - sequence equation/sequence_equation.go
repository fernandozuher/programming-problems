// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isfullscreen=true

package main

import "fmt"

func main() {
    var size int = ReadANumber()
    var array []int = ReadAnArray(size)

    var permutatedArray []int = PermutationEquation(array)
    PrintArray(permutatedArray)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func ReadAnArray(size int) []int {
        var array []int = make([]int, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func PermutationEquation(array []int) []int {
        var elementsPositionsArray []int = GenerateElementsPositionsArray(array)
        var permutatedArray []int = GeneratePermutatedArray(elementsPositionsArray)
        return permutatedArray
    }

        func GenerateElementsPositionsArray(array []int) []int {
            var elementsPositionsArray []int = make([]int, len(array))
            for i, element := range array {
                elementsPositionsArray[element-1] = i
            }
            return elementsPositionsArray
        }

        func GeneratePermutatedArray(array []int) []int {
            var permutatedArray []int = make([]int, len(array))
            for i, element := range array {
                permutatedArray[i] = array[element] + 1
            }
            return permutatedArray
        }

    func PrintArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
