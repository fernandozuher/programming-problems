// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var inputString string
    var nCharacters int64
    _, _ = fmt.Scan(&inputString, &nCharacters)
    const letter = 'a'
    fmt.Println(countInRepeatedString(inputString, letter, nCharacters))
}

func countInRepeatedString(inputString string, letter rune, nCharacters int64) int64 {
    n := int64(len(inputString))
    fullRepeats := nCharacters / n
    nSubstring := nCharacters % n
    substring := inputString[:nSubstring]

    c := string(letter)
    quantity := int64(strings.Count(inputString, c))
    quantity *= fullRepeats
    return quantity + int64(strings.Count(substring, c))
}
