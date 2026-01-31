// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(minJumps(readNumbers(n)))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
func minJumps(clouds []int) int {
    jumps := 0
    for i, n := 0, len(clouds)-1; i < n; jumps, i = jumps+1, i+skip(i, clouds) {
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
