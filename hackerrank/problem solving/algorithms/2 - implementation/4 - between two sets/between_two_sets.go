// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n1, n2 int
    _, _ = fmt.Scan(&n1, &n2)
    a := readNumbers(n1)
    b := readNumbers(n2)
    fmt.Println(betweenTwoSets(a, b))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func betweenTwoSets(a, b []int) int {
    lcmOfA := lcmArray(a)
    gcdOfB := gcdArray(b)

    count := 0
    for i := lcmOfA; i <= gcdOfB; i += lcmOfA {
        if gcdOfB%i == 0 {
            count++
        }
    }
    return count
}

func lcmArray(arr []int) int {
    res := arr[0]
    for _, x := range arr[1:] {
        res = lcm(res, x)
    }
    return res
}

func lcm(a, b int) int {
    return (a * b) / gcd(a, b)
}

func gcdArray(arr []int) int {
    res := arr[0]
    for _, x := range arr[1:] {
        res = gcd(res, x)
    }
    return res
}

func gcd(a, b int) int {
    for b != 0 {
        a, b = b, a%b
    }
    return a
}
