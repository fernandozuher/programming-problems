// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

const nRowsColumns = 6

func main() {
    var matrix [nRowsColumns][nRowsColumns]int = readMatrix()
    var maxSum int = calculateMaxSum(matrix)
    fmt.Println(maxSum)
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
        var maxSum int = math.MinInt

        for i, beforeRowsColumnsLimit := 1, 5; i < beforeRowsColumnsLimit; i++ {
            for j := 1; j < beforeRowsColumnsLimit; j++ {
                var currentSum int = sumAround(matrix, i, j)

                if currentSum > maxSum {
                    maxSum = currentSum
                }
            }
        }

        return maxSum
    }

        func sumAround(matrix [nRowsColumns][nRowsColumns]int, i int, j int) int {
            return matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] +
                matrix[i][j] +
                matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1]
        }
