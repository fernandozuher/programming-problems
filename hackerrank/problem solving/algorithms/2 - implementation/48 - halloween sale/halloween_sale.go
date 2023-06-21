// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var gameDefaultPrice int = readANumber()
    var discount int = readANumber()
    var gameMinimumPrice int = readANumber()
    var budget int = readANumber()

    fmt.Println(howManyGamesCanBeBought(gameDefaultPrice, discount, gameMinimumPrice, budget))
}

func readANumber() int {
    var number int
    fmt.Scan(&number)
    return number
}

func howManyGamesCanBeBought(gameDefaultPrice int, discount int, gameMinimumPrice int, budget int) int {
    var gamesCanBeBoughtQuantity int = 0

    for currentGamePrice, currentBudget := gameDefaultPrice, budget-gameDefaultPrice; currentBudget >= 0; {
        gamesCanBeBoughtQuantity++
        currentGamePrice -= discount

        if currentGamePrice >= gameMinimumPrice {
            currentBudget -= currentGamePrice
        } else {
            currentBudget -= gameMinimumPrice
        }
    }

    return gamesCanBeBoughtQuantity
}
