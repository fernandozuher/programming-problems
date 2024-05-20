// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var nRowsColumns int
    fmt.Scan(&nRowsColumns)
    var matrix []string = readSquareMatrix(nRowsColumns)

    changeMatrixToCavityMap(matrix)
    for _, x := range matrix {
        fmt.Println(x)
    }
}

    func readSquareMatrix(n int) []string {
        matrix := make([]string, n)
        for i := range n {
            fmt.Scan(&matrix[i])
        }
        return matrix
    }

    func changeMatrixToCavityMap(matrix []string) {
        for i, n := 1, len(matrix)-1; i < n; i++ {
            for j := 1; j < n; j++ {
                if isCellCavity(matrix, i, j) {
                    matrix[i] = matrix[i][:j] + string('X') + matrix[i][j+1:]
                }
            }
        }
    }

        func isCellCavity(matrix []string, i int, j int) bool {
            return matrix[i-1][j] < matrix[i][j] &&
                matrix[i][j-1] < matrix[i][j] &&
                matrix[i+1][j] < matrix[i][j] &&
                matrix[i][j+1] < matrix[i][j]
        }
