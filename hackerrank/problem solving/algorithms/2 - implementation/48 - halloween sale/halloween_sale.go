// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var defaultPriceGame, discount, minimumPriceGame, budget int
    _, err := fmt.Scan(&defaultPriceGame, &discount, &minimumPriceGame, &budget)
    if err != nil {
        return
    }
    fmt.Println(howManyGamesCanBeBought(defaultPriceGame, discount, minimumPriceGame, budget))
}

    func howManyGamesCanBeBought(defaultPriceGame int, discount int, minimumPriceGame int, budget int) int {
        gamesCanBeBoughtQuantity := 0

        for currentPriceGame, currentBudget := defaultPriceGame, budget-defaultPriceGame; currentBudget >= 0; {
            gamesCanBeBoughtQuantity++
            currentPriceGame -= discount
            currentBudget -= int(math.Max(float64(currentPriceGame), float64(minimumPriceGame)))
        }

        return gamesCanBeBoughtQuantity
    }
