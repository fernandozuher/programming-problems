// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    results := make([]int, n)

    for i := range n {
        var prisoners, sweets, startChair int
        fmt.Scan(&prisoners, &sweets, &startChair)
        results[i] = saveThePrisoner(prisoners, sweets, startChair)
    }

    for _, x := range results {
        fmt.Println(x)
    }
}

func saveThePrisoner(prisoners, sweets, startChair int) int {
    return ((startChair - 1 + sweets - 1) % prisoners) + 1
}
