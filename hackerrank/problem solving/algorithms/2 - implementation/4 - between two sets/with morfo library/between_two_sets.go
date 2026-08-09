// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    a := morfoio.ReadLn[int]()
    b := morfoio.ReadLn[int]()
    fmt.Println(betweenTwoSets(a, b))
}

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
func betweenTwoSets(a, b []int) int {
    lcmOfA := reduce(a, lcm)
    gcdOfB := reduce(b, gcd)

    count := 0
    for i := lcmOfA; i <= gcdOfB; i += lcmOfA {
        if gcdOfB%i == 0 {
            count++
        }
    }
    return count
}

func reduce(arr []int, function func(int, int) int) int {
    acc := arr[0]
    for _, x := range arr[1:] {
        acc = function(acc, x)
    }
    return acc
}

func lcm(a, b int) int {
    return (a * b) / gcd(a, b)
}

func gcd(a, b int) int {
    for b != 0 {
        a, b = b, a%b
    }
    return a
}
