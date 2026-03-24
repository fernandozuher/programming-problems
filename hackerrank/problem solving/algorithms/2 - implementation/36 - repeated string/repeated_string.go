// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var str string
    var nChars int
    _, _ = fmt.Scan(&str, &nChars)
    const letter = "a"
    fmt.Println(countInRepeatedString(str, letter, nChars))
}

// n: length of str
// T: O(n)
// S: O(1) extra space
func countInRepeatedString(str, letter string, nChars int) int {
    fullRepeats := nChars / len(str)
    nSubstr := nChars % len(str)

    count := strings.Count(str, letter)
    count *= fullRepeats
    return count + strings.Count(str[:nSubstr], letter)
}
