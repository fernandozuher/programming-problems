// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, jumpLength int
    _, _ = fmt.Scan(&n, &jumpLength)
    arr := readNumbers(n)
    fmt.Println(jumpingOnTheClouds(arr, jumpLength))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
func jumpingOnTheClouds(clouds []int, jumpLength int) int {
    energy := 100
    cloudIndex := 0

    for {
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
