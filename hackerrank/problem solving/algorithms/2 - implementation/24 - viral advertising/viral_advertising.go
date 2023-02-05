// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var days int
    fmt.Scan(&days)

    var cumulativeLikes int = viralAdvertising(days)
    fmt.Println(cumulativeLikes)
}

    func viralAdvertising(days int) int {
        var shared, liked, cumulative int = 5, 0, 0

        for i := 0; i < days; i++ {
            liked = shared / 2
            cumulative += liked
            shared = liked * 3
        }

        return cumulative
    }
