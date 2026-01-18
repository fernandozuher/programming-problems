// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var days int
    _, _ = fmt.Scan(&days)
    fmt.Println(viralAdvertising(days))
}

// n: days
// T: O(n)
// S: O(1) extra space
func viralAdvertising(days int) int {
    cumulative := 0
    for shared := 5; days > 0; days-- {
        liked := shared / 2
        shared = liked * 3
        cumulative += liked
    }
    return cumulative
}
