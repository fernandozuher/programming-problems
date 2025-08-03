// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    cancelledClasses := make([]bool, n)

    for i := range cancelledClasses {
        var n, threshold int
        fmt.Scan(&n, &threshold)
        arrivalTimes := readNumbers(n)
        cancelledClasses[i] = angryProfessor(arrivalTimes, threshold)
    }

    for _, cancelled := range cancelledClasses {
        if cancelled {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func angryProfessor(arrivalTimes []int, threshold int) bool {
    count := 0
    for _, t := range arrivalTimes {
        if t <= 0 {
            count++
        }
    }
    return count < threshold
}
