// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

type Input struct {
    itemNotEaten  int
    mealCosts     []int
    amountCharged int
}

func main() {
    data := readInput()
    if charged := bonAppetit(data); charged > 0 {
        fmt.Println(charged)
    } else {
        fmt.Println("Bon Appetit")
    }
}

func readInput() Input {
    var data Input
    n := morfoio.Read[int]()
    data.itemNotEaten = morfoio.Read[int]()
    data.mealCosts = morfoio.ReadN[int](n)
    data.amountCharged = morfoio.Read[int]()
    return data
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
func bonAppetit(data Input) int {
    totalCost := 0
    for _, x := range data.mealCosts {
        totalCost += x
    }
    totalSharedCost := totalCost - data.mealCosts[data.itemNotEaten]
    totalSharedCost /= 2
    return data.amountCharged - totalSharedCost
}
