// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    matrix := readMatrix(n)
    changeMatrixToCavityMap(matrix)
    for _, x := range matrix {
        fmt.Println(string(x))
    }
}

func readMatrix(n int) [][]byte {
    matrix := make([][]byte, n)
    for i := range matrix {
        var x string
        _, _ = fmt.Scan(&x)
        matrix[i] = []byte(x)
    }
    return matrix
}

// n: length of rows/cols of matrix
// T: O(n^2)
// S: O(1) extra space
func changeMatrixToCavityMap(matrix [][]byte) {
    for i, n := 1, len(matrix)-1; i < n; i++ {
        for j := 1; j < n; j++ {
            if isCellCavity(matrix, i, j) {
                matrix[i][j] = 'X'
            }
        }
    }
}

func isCellCavity(matrix [][]byte, i, j int) bool {
    c := matrix[i][j]
    return matrix[i-1][j] < c &&
        matrix[i][j-1] < c &&
        matrix[i+1][j] < c &&
        matrix[i][j+1] < c
}
