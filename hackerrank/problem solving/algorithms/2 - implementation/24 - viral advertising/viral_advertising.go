// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var days int
    fmt.Scan(&days)
    fmt.Println(viralAdvertising(days))
}

    func viralAdvertising(days int) int {
        var shared, liked, cumulative int = 5, 0, 0

        for ; days > 0; days-- {
            liked = shared / 2
            cumulative += liked
            shared = liked * 3
        }

        return cumulative
    }
