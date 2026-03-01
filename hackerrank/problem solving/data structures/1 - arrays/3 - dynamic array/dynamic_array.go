// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, nQueries int
    _, _ = fmt.Scan(&n, &nQueries)

    array := make([][]int, n)
    var answers []int
    lastAnswer := 0

    for i := 0; i < nQueries; i++ {
        var typeI, x, y int
        _, _ = fmt.Scan(&typeI, &x, &y)

        index := (x ^ lastAnswer) % n

        if typeI == 1 {
            array[index] = append(array[index], y)
        } else {
            j := y % len(array[index])
            lastAnswer = array[index][j]
            answers = append(answers, lastAnswer)
        }
    }

    for _, x := range answers {
        fmt.Println(x)
    }
}
