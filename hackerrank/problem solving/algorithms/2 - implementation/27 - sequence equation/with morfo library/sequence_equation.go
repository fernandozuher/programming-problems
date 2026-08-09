// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

package main

import "morfo/morfoio"

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int]()
    morfoio.Println(sequenceEquation(arr))
}

// n: length of arr/res
// T: O(n)
// S: O(n) extra space
func sequenceEquation(arr []int) []int {
    valuesToIndex := make([]int, len(arr))
    for i, val := range arr {
        valuesToIndex[val-1] = i
    }

    res := make([]int, len(arr))
    for i, val := range valuesToIndex {
        res[i] = valuesToIndex[val] + 1
    }

    return res
}
