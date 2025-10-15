// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var price, discount, minPrice, budget int
    _, _ = fmt.Scan(&price, &discount, &minPrice, &budget)
    fmt.Println(howManyGamesCanBeBought(price, discount, minPrice, budget))
}

func howManyGamesCanBeBought(price, discount, minPrice, budget int) int {
    count := 0
    for budget >= price {
        count++
        budget -= price
        price = max(price-discount, minPrice)
    }
    return count
}
