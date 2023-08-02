// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    for i := 0; i < n; i++ {
        var word string
        fmt.Scan(&word)
        var word1, word2 string
        isWord1Turn := true

        for _, ch := range word {
            if isWord1Turn {
                word1 += string(ch)
            } else {
                word2 += string(ch)
            }
            isWord1Turn = !isWord1Turn
        }

        fmt.Println(word1, word2)
    }
}
