// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    for range n {
        var size, threshold int
        fmt.Scan(&size, &threshold)
        arrivalTimes := readNumbers(size)

        if angryProfessor(arrivalTimes, threshold) {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        fmt.Scan(&arr[i])
    }
    return arr
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
