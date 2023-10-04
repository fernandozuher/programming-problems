// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    array := make([]int, n)
    for i, _ := range array {
        fmt.Scan(&array[i])
    }

    fmt.Printf("Array is sorted in %d swaps.", bubbleSort(array))
    fmt.Printf("\nFirst Element: %d", array[0])
    fmt.Printf("\nLast Element: %d", array[len(array)-1])
}

    func bubbleSort(a []int) int {
        numberOfSwaps := 0

        for n := len(a) - 1; n > 0; n-- {
            for i := 0; i < n; i++ {
                if a[i] > a[i+1] {
                    a[i], a[i+1] = a[i+1], a[i]
                    numberOfSwaps++
                }
            }

            if numberOfSwaps == 0 {
                break
            }
        }

        return numberOfSwaps
    }
