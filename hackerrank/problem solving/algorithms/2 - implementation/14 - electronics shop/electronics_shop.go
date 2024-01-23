// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var budget, nKeyboardCosts, nUsbDriveCosts int
    fmt.Scanf("%d %d %d", &budget, &nKeyboardCosts, &nUsbDriveCosts)

    var keyboardCosts []int = readIntArray(nKeyboardCosts)
    var usbDriveCosts []int = readIntArray(nUsbDriveCosts)

    sort.Ints(keyboardCosts)
    sort.Ints(usbDriveCosts)

    fmt.Println(calculateMoneySpent(keyboardCosts, usbDriveCosts, budget))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func calculateMoneySpent(keyboardCosts []int, usbDriveCosts []int, budget int) int {
        var moneyThatCanBeSpent int = 0

        for i := 0; i < len(keyboardCosts); i++ {

            if isNextCostEqualToCurrentOne(keyboardCosts, i) {
                continue
            }

            for j := 0; j < len(usbDriveCosts); j++ {

                if isNextCostEqualToCurrentOne(usbDriveCosts, j) {
                    continue
                }

                var sum int = keyboardCosts[i] + usbDriveCosts[j]

                if isSumAffordableByBudget(sum, budget) {
                    moneyThatCanBeSpent = updateCost(sum, moneyThatCanBeSpent)
                } else {
                    break
                }
            }
        }

        if moneyThatCanBeSpent > 0 {
            return moneyThatCanBeSpent
        } else {
            return -1
        }
    }

        func isNextCostEqualToCurrentOne(deviceCosts []int, i int) bool {
            return i < len(deviceCosts)-1 && deviceCosts[i] == deviceCosts[i+1]
        }

        func isSumAffordableByBudget(sum int, budget int) bool {
            return sum <= budget
        }

        func updateCost(sum int, moneyThatCanBeSpent int) int {
            return int(math.Max(float64(sum), float64(moneyThatCanBeSpent)))
        }
