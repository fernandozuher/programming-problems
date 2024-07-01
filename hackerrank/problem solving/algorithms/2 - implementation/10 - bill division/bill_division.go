// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var data Input
    var n int
    fmt.Scan(&n, &data.itemAnnaDidntConsume)
    data.costOfEachMeal = readIntArray(n)
    fmt.Scan(&data.brianChargedAnna)

    var brianOverchargedAnna int = bonAppetit(data)
    printOutput(brianOverchargedAnna)
}

type Input struct {
    itemAnnaDidntConsume int
    costOfEachMeal       []int
    brianChargedAnna     int
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func bonAppetit(data Input) int {
    var annaCost int = calculateAnnaCost(data.costOfEachMeal, data.itemAnnaDidntConsume)
    return howMuchBrianOverchargedAnna(data.brianChargedAnna, annaCost)
}

func calculateAnnaCost(costOfEachMeal []int, itemAnnaDidntConsume int) int {
    sum := 0
    for _, x := range costOfEachMeal {
        sum += x
    }
    return (sum - costOfEachMeal[itemAnnaDidntConsume]) / 2
}

func howMuchBrianOverchargedAnna(brianChargedAnna int, annaCost int) int {
    if annaCost != brianChargedAnna {
        return brianChargedAnna - annaCost
    }
    return 0
}

func printOutput(charged int) {
    if charged > 0 {
        fmt.Print(charged)
    } else {
        fmt.Print("Bon Appetit")
    }
}
