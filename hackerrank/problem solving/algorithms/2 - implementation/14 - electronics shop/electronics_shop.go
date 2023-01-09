// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    var inputLine []int = readLineAsIntArray(scanner)
    var budget int = inputLine[0]

    var keyboardCosts []int = readLineAsIntArray(scanner)
    var usbDriveCosts []int = readLineAsIntArray(scanner)

    sort.Ints(keyboardCosts)
    sort.Ints(usbDriveCosts)

    var result int = getMoneySpent(keyboardCosts, usbDriveCosts, budget)
    fmt.Print(result)
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
        var line string

        if scanner.Scan() {
            line = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        inputStringArray := strings.Split(line, " ")
        inputLine := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            checkError(err)
            inputLine[i] = number
        }
        return inputLine
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func getMoneySpent(keyboardCosts []int, usbDriveCosts []int, budget int) int {
        canBeSpent := 0

        for i := 0; i < len(keyboardCosts); i++ {
            
            if isNextCostEqualToCurrentOne(keyboardCosts, i) {
                continue
            }

            for j := 0; j < len(usbDriveCosts); j++ {
                
                if isNextCostEqualToCurrentOne(usbDriveCosts, j) {
                    continue
                }

                var sum int = keyboardCosts[i] + usbDriveCosts[j]

                if isSumInsideBudget(sum, budget) {
                    canBeSpent = updateCost(sum, canBeSpent)
                } else {
                    break
                }
            }
        }

        if canBeSpent > 0 {
            return canBeSpent
        } else {
            return -1
        }
    }

        func isNextCostEqualToCurrentOne(deviceCosts []int, currentIndex int) bool {
            return currentIndex < len(deviceCosts) - 1 && deviceCosts[currentIndex] == deviceCosts[currentIndex + 1]
        }

        func isSumInsideBudget(sum int, budget int) bool {
            return sum <= budget
        }

        func updateCost(sum int, canBeSpent int) int {
            return int(math.Max(float64(sum), float64(canBeSpent)))
        }
