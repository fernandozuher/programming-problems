// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    matrix := readMatrix()
    fmt.Println(maxHourglassSum(matrix))
}

func readMatrix() [][]int {
    N := 6
    matrix := make([][]int, N)
    for i := range N {
        matrix[i] = make([]int, N)
        for j := range N {
            _, _ = fmt.Scan(&matrix[i][j])
        }
    }
    return matrix
}

// T: O(1)
// S: O(1) extra space
func maxHourglassSum(matrix [][]int) int {
    maxSum := math.MinInt32

    for i, rowsCols := 1, 4; i <= rowsCols; i++ {
        for j := 1; j <= rowsCols; j++ {
            currentSum := hourglassSum(matrix, i, j)
            maxSum = max(maxSum, currentSum)
        }
    }

    return maxSum
}

func hourglassSum(matrix [][]int, i, j int) int {
    subrow1FirstIndex := i - 1
    subrow3FirstIndex := i + 1
    firstColIndex := j - 1
    end := firstColIndex + 3

    subrow1 := matrix[subrow1FirstIndex][firstColIndex:end]
    subrow3 := matrix[subrow3FirstIndex][firstColIndex:end]

    sum := 0
    for i := range subrow1 {
        sum += subrow1[i] + subrow3[i]
    }

    return sum + matrix[i][j]
}
