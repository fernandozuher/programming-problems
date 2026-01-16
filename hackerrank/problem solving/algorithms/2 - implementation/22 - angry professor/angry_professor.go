// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)

    for range n {
        var size, threshold int
        _, _ = fmt.Scan(&size, &threshold)
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
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// k: length of array arrivalTimes
// T: O(k)
// S: O(1) extra space
func angryProfessor(arrivalTimes []int, threshold int) bool {
    onTime := 0
    for _, t := range arrivalTimes {
        if t <= 0 {
            onTime++
        }
    }
    return onTime < threshold
}
