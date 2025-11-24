// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    for range n {
        var number int
        _, _ = fmt.Scan(&number)
        fmt.Println(findDigits(number))
    }
}

func findDigits(n int) int {
    divisors := 0
    originalNumber := n

    for ; n != 0; n /= 10 {
        divisor := n % 10
        if divisor != 0 && originalNumber%divisor == 0 {
            divisors++
        }
    }

    return divisors
}
