// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

package main

import "fmt"


func main() {
    var nTestCases int = ReadANumber()
    var prisonersChairNumberToWarn []int = ReadTestCasesAndSaveThePrisoners(nTestCases)
    PrintResults(prisonersChairNumberToWarn)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func ReadTestCasesAndSaveThePrisoners(nTestCases int) []int {
        var prisonersChairNumberToWarn []int = make([]int, nTestCases)

        for i := 0; i < nTestCases; i++ {
            var testCase []int = ReadTestCase()
            prisonersChairNumberToWarn[i] = SaveThePrisoner(testCase)
        }

        return prisonersChairNumberToWarn
    }

        func ReadTestCase() []int {
            const SIZE_TEST_CASE int = 3
            var testCase []int = make([]int, SIZE_TEST_CASE)
            fmt.Scanf("%d %d %d", &testCase[0], &testCase[1], &testCase[2])

            return testCase
        }

        func SaveThePrisoner(testCase []int) int {
            var prisoners int = testCase[0]
            var sweets int = testCase[1]
            var chairNumberToBegin int = testCase[2]

            var prisonerChairNumberToWarn int = chairNumberToBegin + (sweets - 1)

            if prisonerChairNumberToWarn < prisoners {
                return prisonerChairNumberToWarn
            } else {
                prisonerChairNumberToWarn %= prisoners
                if prisonerChairNumberToWarn == 0 {
                    return prisoners
                } else {
                    return prisonerChairNumberToWarn
                }
            }
        }

    func PrintResults(array []int) {
        for _, number := range array {
            fmt.Println(number)
        }
    }
