// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    for range n {
        var prisoners, sweets, startChair int
        _, _ = fmt.Scan(&prisoners, &sweets, &startChair)
        fmt.Println(saveThePrisoner(prisoners, sweets, startChair))
    }
}

// T: O(1)
// S: O(1) extra space
func saveThePrisoner(prisoners, sweets, startChair int) int {
    return ((startChair - 1 + sweets - 1) % prisoners) + 1
}
