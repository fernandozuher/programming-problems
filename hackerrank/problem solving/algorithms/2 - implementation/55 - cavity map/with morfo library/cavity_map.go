// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

package main

import "morfo/morfoio"

func main() {
    n := morfoio.Read[int]()
    matrix := readMatrix(n)
    changeMatrixToCavityMap(matrix)
    lines := make([]string, len(matrix))
    for i, x := range matrix {
        lines[i] = string(x)
    }
    morfoio.Println(lines)
}

func readMatrix(n int) [][]byte {
    matrix := make([][]byte, n)
    for i := range matrix {
        matrix[i] = []byte(morfoio.Read[string]())
    }
    return matrix
}

// n: length of matrix' rows
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
