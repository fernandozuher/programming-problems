// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    matrix := readMatrix(n)
    changeMatrixToCavityMap(matrix)
    for _, x := range matrix {
        fmt.Println(x)
    }
}

func readMatrix(n int) []string {
    matrix := make([]string, n)
    for i := range n {
        _, _ = fmt.Scan(&matrix[i])
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

func isCellCavity(matrix []string, i, j int) bool {
    return matrix[i-1][j] < matrix[i][j] &&
        matrix[i][j-1] < matrix[i][j] &&
        matrix[i+1][j] < matrix[i][j] &&
        matrix[i][j+1] < matrix[i][j]
}
