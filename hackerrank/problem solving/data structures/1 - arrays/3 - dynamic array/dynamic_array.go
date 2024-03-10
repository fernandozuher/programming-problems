// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

// Time limit exceeded for a few test cases

package main

import "fmt"

func main() {
    var n, nQueries int
    fmt.Scan(&n, &nQueries)

    var array [][]int = make([][]int, n)
    answers := []int{}
    lastAnswer := 0

    for i := 0; i < nQueries; i++ {
        var typeI, x, y int
        fmt.Scanf("%d %d %d", &typeI, &x, &y)

        var index int = (x ^ lastAnswer) % n

        if typeI == 1 {
            array[index] = append(array[index], y)
        } else {
            var j int = y % len(array[index])
            lastAnswer = array[index][j]
            answers = append(answers, lastAnswer)
        }
    }

    for _, x := range answers {
        fmt.Println(x)
    }
}
