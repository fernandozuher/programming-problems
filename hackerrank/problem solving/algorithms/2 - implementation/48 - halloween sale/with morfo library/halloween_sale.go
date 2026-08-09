// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    price := morfoio.Read[int]()
    discount := morfoio.Read[int]()
    minPrice := morfoio.Read[int]()
    budget := morfoio.Read[int]()
    fmt.Println(howManyGamesCanBeBought(price, discount, minPrice, budget))
}

// T: O(budget / minPrice)
// S: O(1) extra space
func howManyGamesCanBeBought(price, discount, minPrice, budget int) int {
    count := 0
    for budget >= price {
        count++
        budget -= price
        price = max(price-discount, minPrice)
    }
    return count
}
