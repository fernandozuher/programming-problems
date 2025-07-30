// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import "fmt"

func main() {
    printOutput(bonAppetit(readInput()))
}

func readInput() Input {
    var data Input
    var n int
    fmt.Scan(&n, &data.itemNotEaten)
    data.mealCosts = readNumbers(n)
    fmt.Scan(&data.amountCharged)
    return data
}

type Input struct {
    itemNotEaten  int
    mealCosts     []int
    amountCharged int
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func bonAppetit(data Input) int {
    return data.amountCharged - computeActualShare(data.mealCosts, data.itemNotEaten)
}

func computeActualShare(mealCosts []int, itemNotEaten int) int {
    totalCost := 0
    for _, x := range mealCosts {
        totalCost += x
    }
    totalSharedCost := totalCost - mealCosts[itemNotEaten]
    return totalSharedCost / 2
}

func printOutput(charged int) {
    if charged > 0 {
        fmt.Println(charged)
    } else {
        fmt.Println("Bon Appetit")
    }
}
