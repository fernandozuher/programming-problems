// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, itemAnnaDidntConsume int
    fmt.Scan(&n, &itemAnnaDidntConsume)

    var costOfEachMeal []int = readIntArray(n)
    var brianChargedAnna int
    fmt.Scan(&brianChargedAnna)

    var brianOverchargedAna int = bonAppetit(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna)
    printOutput(brianOverchargedAna)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func bonAppetit(costOfEachMeal []int, itemAnnaDidntConsume int, brianChargedAnna int) int {
        var annaCost int = calculateAnnaCost(costOfEachMeal, itemAnnaDidntConsume)
        return calculateHowMuchBrianOverchargedAnna(brianChargedAnna, annaCost)
    }

        func calculateAnnaCost(costOfEachMeal []int, itemAnnaDidntConsume int) int {
            var sum int = 0
            for _, number := range costOfEachMeal {
                sum += number
            }
            var annaCost int = (sum - costOfEachMeal[itemAnnaDidntConsume]) / 2
            return annaCost
        }

        func calculateHowMuchBrianOverchargedAnna(brianChargedAnna int, annaCost int) int {
            if annaCost != brianChargedAnna {
                return brianChargedAnna - annaCost
            }
            return 0
        }

    func printOutput(charged int) {
        if (charged > 0) {
            fmt.Println(charged);
        } else {
            fmt.Println("Bon Appetit");
        }
    }
