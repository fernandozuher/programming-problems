// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

package main

import "fmt"

func main() {
    numbers := readInput()
    nSwaps := bubbleSort(numbers)
    fmt.Printf("Array is sorted in %d swaps.", nSwaps)
    fmt.Printf("\nFirst Element: %d", numbers[0])
    fmt.Printf("\nLast Element: %d", numbers[len(numbers)-1])
}

func readInput() []int {
    var n int
    fmt.Scan(&n)
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func bubbleSort(a []int) int {
    totalSwaps, end := 0, len(a)
    for end > 0 {
        nSwaps, newEnd := sortSlice(a[0:end])
        totalSwaps += nSwaps
        end = newEnd
    }
    return totalSwaps
}

func sortSlice(a []int) (int, int) {
    nSwaps, newEnd := 0, 0
    for i := range len(a) - 1 {
        if a[i] > a[i+1] {
            a[i], a[i+1] = a[i+1], a[i]
            nSwaps++
            newEnd = i + 1
        }
    }
    return nSwaps, newEnd
}
