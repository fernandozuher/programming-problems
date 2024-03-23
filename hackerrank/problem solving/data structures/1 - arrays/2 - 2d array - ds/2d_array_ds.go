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
            var subrow1FirstIndex int = i - 1
            var subrow3FirstIndex int = i + 1
            var firstColIndex int = j - 1
            var end int = firstColIndex + 3

            subrow1 := matrix[subrow1FirstIndex][firstColIndex:end]
            subrow3 := matrix[subrow3FirstIndex][firstColIndex:end]

            sum := 0
            for i := range subrow1 {
                sum += subrow1[i] + subrow3[i]
            }

            sum += matrix[i][j]

            return sum
        }
