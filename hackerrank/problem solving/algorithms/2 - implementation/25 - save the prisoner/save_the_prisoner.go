// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    prisonersChairNumberToWarn := make([]int, n)

    for i := 0; i < n; i++ {
        var prisoners, sweets, chairNumberToBegin int
        fmt.Scanf("%d %d %d", &prisoners, &sweets, &chairNumberToBegin)
        prisonersChairNumberToWarn[i] = saveThePrisoner(prisoners, sweets, chairNumberToBegin)
    }

    printArray(prisonersChairNumberToWarn)
}

    func saveThePrisoner(prisoners int, sweets int, chairNumberToBegin int) int {
        var prisonerChairNumberToWarn int = chairNumberToBegin + (sweets - 1)
        x := prisonerChairNumberToWarn

        if x > prisoners {
            x %= prisoners
            if x == 0 {
                x = prisoners
            }
        }

        return x
    }

    func printArray(array []int) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
