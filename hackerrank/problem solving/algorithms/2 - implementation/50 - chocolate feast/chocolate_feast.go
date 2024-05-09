// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, err := fmt.Scan(&n)
    if err != nil {
        return
    }
    output := make([]int, n)

    for i := 0; i < n; i++ {
        var amountOfMoney, chocolateBarCost, nWrappersToTurnInBar int
        _, err := fmt.Scan(&amountOfMoney, &chocolateBarCost, &nWrappersToTurnInBar)
        if err != nil {
            return
        }
        output[i] = howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar)
    }

    for _, x := range output {
        fmt.Println(x)
    }
}

    func howManyChocolatesCanBeEaten(amountOfMoney int, chocolateBarCost int, nWrappersToTurnInBar int) int {
        eatenChocolates := amountOfMoney / chocolateBarCost

        for availableWrappers := eatenChocolates; availableWrappers >= nWrappersToTurnInBar; {
            chocolatesForFree := availableWrappers / nWrappersToTurnInBar
            availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree
            eatenChocolates += chocolatesForFree
        }

        return eatenChocolates
    }
