// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var mealCost float64
    var tipPercent, taxPercent int
    fmt.Scan(&mealCost, &tipPercent, &taxPercent)
    solve(mealCost, tipPercent, taxPercent)
}

func solve(mealCost float64, tipPercent int, taxPercent int) {
    totalCost := mealCost + mealCost*float64(tipPercent)/100.0 + mealCost*float64(taxPercent)/100.0
    fmt.Printf("%.0f", totalCost)
}
