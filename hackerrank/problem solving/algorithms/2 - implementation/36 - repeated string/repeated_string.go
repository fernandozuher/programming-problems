// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var inputString string
    var nCharacters int64
    fmt.Scan(&inputString, &nCharacters)
    const letter = 'a'
    fmt.Println(countInRepeatedString(inputString, letter, nCharacters))
}

    func countInRepeatedString(inputString string, letter rune, nCharacters int64) int64 {
        var repeatedEntireString int64 = nCharacters / int64(len(inputString))
        var nSubstring int64 = nCharacters % int64(len(inputString))
        var substring string = inputString[:nSubstring]

        var quantity int64 = int64(strings.Count(inputString, string(letter)))
        quantity *= repeatedEntireString
        quantity += int64(strings.Count(substring, string(letter)))

        return quantity
    }
