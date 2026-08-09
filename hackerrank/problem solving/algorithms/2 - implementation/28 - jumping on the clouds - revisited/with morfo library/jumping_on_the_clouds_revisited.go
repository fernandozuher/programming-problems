// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInput()
    jumpLength := morfoio.Read[int]()
    arr := morfoio.ReadLn[int]()
    fmt.Println(jumpingOnTheClouds(arr, jumpLength))
}

// n: length of clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
func jumpingOnTheClouds(clouds []int, jumpLength int) int {
    energy := 100

    for cloudIndex := 0; ; {
        energy -= 1
        if clouds[cloudIndex] != 0 {
            energy -= 2
        }
        cloudIndex = (cloudIndex + jumpLength) % len(clouds)
        if cloudIndex == 0 {
            break
        }
    }

    return energy
}
