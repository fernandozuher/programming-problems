// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nRowsColumns int
    fmt.Scan(&nRowsColumns)

    var matrix []string = readSquareMatrix(nRowsColumns)

    changeMatrixToCavityMap(&matrix)
    for _, element := range matrix {
        fmt.Println(element)
    }
}

    func readSquareMatrix(size int) []string {
        var matrix []string = make([]string, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&matrix[i])
        }
        return matrix
    }

    func changeMatrixToCavityMap(matrix *[]string) {
        const CAVITY string = "X"
        for i, newSize := 1, len(*matrix)-1; i < newSize; i++ {
            for j := 1; j < newSize; j++ {
                if isCellCavity(matrix, i, j) {
                    (*matrix)[i] = generateStringWithCavity(&((*matrix)[i]), j)
                }
            }
        }
    }

        func isCellCavity(matrix *[]string, i int, j int) bool {
            return (*matrix)[i-1][j] < (*matrix)[i][j] &&
                (*matrix)[i][j-1] < (*matrix)[i][j] &&
                (*matrix)[i+1][j] < (*matrix)[i][j] &&
                (*matrix)[i][j+1] < (*matrix)[i][j]
        }

        func generateStringWithCavity(line *string, indexToPutCavity int) string {
            const cavity byte = 'X'
            stringToChar := []byte(*line)
            stringToChar[indexToPutCavity] = cavity
            return string(stringToChar)
        }
