// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, maximumHeightCanJump int
    fmt.Scan(&n, &maximumHeightCanJump)
    var hurdlesHeights []int = readIntArray(n)
    fmt.Println(hurdleRace(hurdlesHeights, maximumHeightCanJump))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func hurdleRace(hurdlesHeights []int, maximumHeightCanJump int) int {
        var highestHurdle int = max(hurdlesHeights)

        if highestHurdle > maximumHeightCanJump {
            return highestHurdle - maximumHeightCanJump
        } else {
            return 0
        }
    }

        func max(array []int) int {
            var max int = 0
            for _, element := range array {
                if max < element {
                    max = element
                }
            }
            return max
        }
