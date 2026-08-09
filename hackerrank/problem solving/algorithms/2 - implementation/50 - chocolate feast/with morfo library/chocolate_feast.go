// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int]()
    for range n {
        fmt.Println(howManyChocolatesCanBeEaten(readInput()))
    }
}

func readInput() (int, int, int) {
    vals := morfoio.ReadLn[int]()
    return vals[0], vals[1], vals[2]
}

// T: O(log(money / cost))
// S: O(1) extra space
func howManyChocolatesCanBeEaten(money, cost, wrappersNeeded int) int {
    chocolates := money / cost

    for wrappers := chocolates; wrappers >= wrappersNeeded; {
        freeChocolates := wrappers / wrappersNeeded
        wrappers = wrappers%wrappersNeeded + freeChocolates
        chocolates += freeChocolates
    }

    return chocolates
}
