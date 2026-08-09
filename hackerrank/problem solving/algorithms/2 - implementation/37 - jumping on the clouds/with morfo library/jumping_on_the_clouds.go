// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    clouds := morfoio.ReadLn[int]()
    fmt.Println(minJumps(clouds))
}

// n: length of clouds
// T: O(n)
// S: O(1) extra space
func minJumps(clouds []int) int {
    jumps := 0
    for i, n := 0, len(clouds)-1; i < n; i += skip(i, clouds) {
        jumps++
    }
    return jumps
}

func skip(idx int, clouds []int) int {
    if isNextSecondCloudCumulus(idx, clouds) {
        return 2
    }
    return 1
}

func isNextSecondCloudCumulus(idx int, clouds []int) bool {
    return idx+2 < len(clouds) && clouds[idx+2] == 0
}
