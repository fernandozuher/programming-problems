// https://www.hackerrank.com/challenges/permutation-equation/problem?isfullscreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    var permutatedArray []int = permutationEquation(array)
    printArray(permutatedArray)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func permutationEquation(array []int) []int {
        var elementsPositionsArray []int = generateElementsPositionsArray(array)
        return generatePermutatedArray(elementsPositionsArray)
    }

        func generateElementsPositionsArray(array []int) []int {
            elementsPositionsArray := make([]int, len(array))
            for i, element := range array {
                elementsPositionsArray[element-1] = i
            }
            return elementsPositionsArray
        }

        func generatePermutatedArray(array []int) []int {
            permutatedArray := make([]int, len(array))
            for i, element := range array {
                permutatedArray[i] = array[element] + 1
            }
            return permutatedArray
        }

    func printArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
