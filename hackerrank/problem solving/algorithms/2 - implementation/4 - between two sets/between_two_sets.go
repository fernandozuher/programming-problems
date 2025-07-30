// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n1, n2 int
    fmt.Scan(&n1, &n2)
    numbersA := readNumbers(n1)
    numbersB := readNumbers(n2)
    fmt.Println(betweenTwoSets(numbersA, numbersB))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
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

func lcmArray(numbers []int) int {
    result := numbers[0]
    for _, x := range numbers[1:] {
        result = lcm(result, x)
    }
    return result
}

func lcm(a, b int) int {
    return (a * b) / gcd(a, b)
}

func gcdArray(numbers []int) int {
    result := numbers[0]
    for _, x := range numbers[1:] {
        result = gcd(result, x)
    }
    return result
}

func gcd(a, b int) int {
    for b != 0 {
        a, b = b, a%b
    }
    return a
}
