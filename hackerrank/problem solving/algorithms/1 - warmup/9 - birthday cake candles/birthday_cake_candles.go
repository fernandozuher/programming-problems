// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    fmt.Println(birthdayCakeCandles(array))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func birthdayCakeCandles(candles []int) int {
        var maxElement, countMax int = 0, 0

        for _, number := range candles {
            if maxElement < number {
                maxElement = number
                countMax = 1
            } else if maxElement == number {
                countMax++
            }
        }

        return countMax
    }
