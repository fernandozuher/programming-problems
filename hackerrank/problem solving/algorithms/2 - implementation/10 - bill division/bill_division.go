// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import "fmt"

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
    var n int
    _, _ = fmt.Scan(&n, &data.itemNotEaten)
    data.mealCosts = readNumbers(n)
    _, _ = fmt.Scan(&data.amountCharged)
    return data
}

type Input struct {
    itemNotEaten  int
    mealCosts     []int
    amountCharged int
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func bonAppetit(data Input) int {
    totalCost := 0
    for _, x := range data.mealCosts {
        totalCost += x
    }
    totalSharedCost := totalCost - data.mealCosts[data.itemNotEaten]
    totalSharedCost /= 2
    return data.amountCharged - totalSharedCost
}
