// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    n := 6
    fmt.Println(maxHourglassSum(readInput(n)))
}

func readInput(n int) [][]int {
    matrix := make([][]int, n)
    for i := range n {
        matrix[i] = make([]int, n)
        for j := range n {
            _, _ = fmt.Scan(&matrix[i][j])
        }
    }
    return matrix
}

func maxHourglassSum(matrix [][]int) int {
    maxSum := math.MinInt32

    for i, rows_cols := 1, 4; i <= rows_cols; i++ {
        for j := 1; j <= rows_cols; j++ {
            currentSum := hourglassSum(matrix, i, j)
            if currentSum > maxSum {
                maxSum = currentSum
            }
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
