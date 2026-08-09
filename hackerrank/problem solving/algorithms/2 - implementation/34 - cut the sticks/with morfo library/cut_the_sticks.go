// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

package main

import (
    "morfo/morfoio"
    "slices"
)

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int]()
    slices.Sort(arr)
    morfoio.Println(cutTheSticks(arr))
}

// n: length of arr
// k: number of distinct values in arr
// k <= n
// T: O(n)
//    Sorting arr beforehand is O(n log n)
// S: O(k) = O(n) extra space
//    Sorting arr beforehand is O(n) extra space
func cutTheSticks(arr []int) []int {
    var res []int
    slow, n := 0, len(arr)

    for fast := range n {
        if arr[slow] == arr[fast] {
            continue
        }
        res = append(res, n-slow)
        slow = fast
    }

    res = append(res, n-slow)
    return res
}
