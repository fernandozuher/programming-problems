// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

const nRowsColumns = 6

func main() {
    matrix := readMatrix()
    fmt.Println(calculateMaxSum(matrix))
}

func readMatrix() [nRowsColumns][nRowsColumns]int {
    matrix := [nRowsColumns][nRowsColumns]int{}

    for i := range matrix {
        for j := range matrix {
            fmt.Scan(&matrix[i][j])
        }
    }

    return matrix
}

func calculateMaxSum(matrix [nRowsColumns][nRowsColumns]int) int {
    maxSum := math.MinInt
    for i, beforeRowsColumnsLimit := 1, 5; i < beforeRowsColumnsLimit; i++ {
        for j := 1; j < beforeRowsColumnsLimit; j++ {
            maxSum = max(maxSum, sumAround(matrix, i, j))
        }
    }
    return maxSum
}

func sumAround(matrix [nRowsColumns][nRowsColumns]int, i int, j int) int {
    return matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] +
        matrix[i][j] +
        matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1]
}
