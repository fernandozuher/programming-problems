// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nTestCases int = readANumber()
    var output []int = solveTestCases(nTestCases)
    for _, element := range output {
        fmt.Println(element)
    }
}

    func readANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func solveTestCases(nTestCases int) []int {
        var output []int = make([]int, nTestCases)

        for i := 0; i < nTestCases; i++ {
            var amountOfMoney int = readANumber()
            var chocolateBarCost int = readANumber()
            var nWrappersToTurnInBar int = readANumber()
            output[i] = howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar)
        }

        return output
    }

        func howManyChocolatesCanBeEaten(amountOfMoney int, chocolateBarCost int, nWrappersToTurnInBar int) int {
            var eatenChocolates int = amountOfMoney / chocolateBarCost

            for availableWrappers := eatenChocolates; availableWrappers >= nWrappersToTurnInBar; {
                var chocolatesForFree int = availableWrappers / nWrappersToTurnInBar
                availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree
                eatenChocolates += chocolatesForFree
            }

            return eatenChocolates
        }
