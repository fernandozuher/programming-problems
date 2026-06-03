// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, nQueries int
    _, _ = fmt.Scan(&n, &nQueries)
    for _, x := range handleQueries(n, nQueries) {
        fmt.Println(x)
    }
}

// T: O(nQueries)
// S: O(n + nQueries) extra space
func handleQueries(n, nQueries int) []int {
    arr := make([][]int, n)
    var answers []int
    lastAnswer := 0

    for range nQueries {
        var typeI, x, y int
        _, _ = fmt.Scan(&typeI, &x, &y)

        index := (x ^ lastAnswer) % n

        if typeI == 1 {
            arr[index] = append(arr[index], y)
        } else {
            j := y % len(arr[index])
            lastAnswer = arr[index][j]
            answers = append(answers, lastAnswer)
        }
    }

    return answers
}
