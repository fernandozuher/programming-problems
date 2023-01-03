// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    input1 := readNNumbersAndPutIntoIntArray(scanner, 2)
    n := input1[0]
    itemAnnaDidntConsume := input1[1]

    costOfEachMeal := readNNumbersAndPutIntoIntArray(scanner, n)
    brianChargedAnna := readNNumbersAndPutIntoIntArray(scanner, 1)

    result := bonAppetit(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna[0])
    fmt.Print(result)
}

    func readNNumbersAndPutIntoIntArray(scanner *bufio.Scanner, n int) []int {
        numbers := make([]int, n)
        
        for i, _ := range numbers {
            _, err := fmt.Scan(&numbers[i])
            checkError(err)
        }
        
        return numbers
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func bonAppetit(costOfEachMeal []int, itemAnnaDidntConsume int, brianChargedAnna int) string {
        annaCost := calculateAnnaCost(costOfEachMeal, itemAnnaDidntConsume)
        result := checkIfBrianOverchargedAnna(brianChargedAnna, annaCost)
        return result
    }

        func calculateAnnaCost(costOfEachMeal []int, itemAnnaDidntConsume int) int {
            sum := 0
            for _, number := range costOfEachMeal {
                sum += number
            }
            annaCost := (sum - costOfEachMeal[itemAnnaDidntConsume]) / 2
            return annaCost
        }

        func checkIfBrianOverchargedAnna(brianChargedAnna int, annaCost int) string {
            if annaCost == brianChargedAnna {
                return "Bon Appetit"
            } else {
                brianOverchargedAna := brianChargedAnna - annaCost
                str := strconv.Itoa(brianOverchargedAna)
                return str 
            }
        }
