// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var input [][]int = ReadInput()
    input = ReduceInputRotations(input)
    input = RotateInputArray(input)
    PrintRotatedArrayElementsAccordingToQueries(input)
}

    func ReadInput() [][]int {
        var arraySize []int = ReadANumberAndReturnItIntoArray()
        var rotationCount []int = ReadANumberAndReturnItIntoArray()
        var queriesSize []int = ReadANumberAndReturnItIntoArray()

        var array []int = ReadArray(arraySize[0])
        var queries []int = ReadArray(queriesSize[0])

        input := make([][]int, 5)
        input[0] = array
        input[1] = arraySize
        input[2] = rotationCount
        input[3] = queries
        input[4] = queriesSize

        return input
    }

        func ReadANumberAndReturnItIntoArray() []int {
            var number []int = make([]int, 1)
            fmt.Scan(&number[0])
            return number
        }

        func ReadArray(size int) []int {
            var array []int = make([]int, size)
            for i, _ := range array {
                fmt.Scan(&array[i])
            }
            return array
        }

    func ReduceInputRotations(input [][]int) [][]int {
        var arraySize int = input[1][0]
        var rotationCount int = input[2][0]

        if arraySize > 1 {
            if rotationCount >= arraySize {
                input[2][0] = rotationCount % arraySize
            } else {
                input[2][0] = rotationCount
            }
        } else {
            input[2][0] = 0
        }

        return input
    }

    func RotateInputArray(input [][]int) [][]int {
        var array []int = input[0]
        var arraySize int = input[1][0]
        var rotationCount int = input[2][0]

        var first_part_new_array []int = array[arraySize-rotationCount:]
        var second_part_new_array []int = array[:arraySize-rotationCount]
        var new_array []int = append(first_part_new_array, second_part_new_array...)

        input[0] = new_array
        return input
    }

    func PrintRotatedArrayElementsAccordingToQueries(input [][]int) {
        var array []int = input[0]
        var queries []int = input[3]

        for _, query := range queries {
            fmt.Println(array[query])
        }
    }
