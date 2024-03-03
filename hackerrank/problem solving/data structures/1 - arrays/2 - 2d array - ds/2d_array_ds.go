// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    n := 6
    matrix := make([][]int, n)

    for i := range matrix {
        matrix[i] = make([]int, n)
        for j := 0; j < n; j++ {
            fmt.Scanf("%d", &matrix[i][j])
        }
    }

    fmt.Println(maxHourglassSum(matrix))
}

    func maxHourglassSum(matrix [][]int) int {
        var maxSum int = math.MinInt32

        for i, rows_cols := 1, 4; i <= rows_cols; i++ {
            for j := 1; j <= rows_cols; j++ {
                var currentSum int = hourglassSum(matrix, i, j)
                if currentSum > maxSum {
                    maxSum = currentSum
                }
            }
        }

        return maxSum
    }

        func hourglassSum(matrix [][]int, i int, j int) int {
            return matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] +
                matrix[i][j] +
                matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1]
        }
