// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    clouds := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &clouds[i])
    }

    fmt.Println(minimumNumberOfJumps(clouds))
}

    func minimumNumberOfJumps(clouds []int) int {
        jumps := 0
        for i, n := 0, len(clouds)-1; i < n; jumps++ {
            i += nextJump(i, clouds)
        }
        return jumps
    }

        func nextJump(index int, clouds []int) int {
            if index+2 < len(clouds) {
                if isNextSecondCloudCumulus := clouds[index+2]; isNextSecondCloudCumulus == 0 {
                    return 2
                }
            }
            return 1
        }
