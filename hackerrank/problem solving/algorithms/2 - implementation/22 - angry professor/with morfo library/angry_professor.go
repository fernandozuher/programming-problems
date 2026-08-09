// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int]()

    for range n {
        morfoio.SkipInput()
        threshold := morfoio.Read[int]()
        arrivalTimes := morfoio.ReadLn[int]()

        if angryProfessor(arrivalTimes, threshold) {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

// k: length of arrivalTimes
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
