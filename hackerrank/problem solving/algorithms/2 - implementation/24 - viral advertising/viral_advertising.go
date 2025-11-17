// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var days int
    fmt.Scan(&days)
    fmt.Println(viralAdvertising(days))
}

// n = days = length of the iteration
// T = O(n)
// S = O(1)
func viralAdvertising(days int) int {
    cumulative := 0

    for shared := 5; days > 0; days-- {
        liked := shared / 2
        cumulative += liked
        shared = liked * 3
    }

    return cumulative
}
