// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    for range n {
        fmt.Println(howManyChocolatesCanBeEaten(readInput()))
    }
}

func readInput() (int, int, int) {
    var money, cost, wrappersNeeded int
    _, _ = fmt.Scan(&money, &cost, &wrappersNeeded)
    return money, cost, wrappersNeeded
}

func howManyChocolatesCanBeEaten(money, cost, wrappersNeeded int) int {
    chocolates := money / cost

    for wrappers := chocolates; wrappers >= wrappersNeeded; {
        freeChocolates := wrappers / wrappersNeeded
        wrappers = wrappers%wrappersNeeded + freeChocolates
        chocolates += freeChocolates
    }

    return chocolates
}
