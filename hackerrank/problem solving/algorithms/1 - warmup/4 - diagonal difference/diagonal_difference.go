// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    var matrix [][]int = readMatrix(n)
    fmt.Println(diagonalDifference(matrix))
}

    func readMatrix(n int) [][]int {
        matrix := make([][]int, n)

        for i := range matrix {
            matrix[i] = make([]int, n)
            for j := 0; j < n; j++ {
                fmt.Scan(&matrix[i][j])
            }
        }

        return matrix
    }

    func diagonalDifference(matrix [][]int) int {
        var primaryDiagonal, secondaryDiagonal int = 0, 0

        for i, j, n := 0, len(matrix)-1, len(matrix); i < n; i, j = i+1, j-1 {
            primaryDiagonal += matrix[j][j]
            secondaryDiagonal += matrix[j][i]
        }

        return int(math.Abs(float64(primaryDiagonal) - float64(secondaryDiagonal)))
    }
