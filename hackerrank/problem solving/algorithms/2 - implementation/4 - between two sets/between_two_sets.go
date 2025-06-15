// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n1, n2 int
    fmt.Scan(&n1, &n2)
    numbers1 := readNumbers(n1)
    numbers2 := readNumbers(n2)

    lcmOfNumbers1 := lcmArray(numbers1)
    gcdOfNumbers2 := gcdArray(numbers2)

    count := 0
    for i := lcmOfNumbers1; i <= gcdOfNumbers2; i += lcmOfNumbers1 {
        if gcdOfNumbers2%i == 0 {
            count++
        }
    }
    fmt.Println(count)
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
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
