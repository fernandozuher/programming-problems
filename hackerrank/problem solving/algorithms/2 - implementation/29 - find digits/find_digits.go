// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    for range n {
        var num int
        _, _ = fmt.Scan(&num)
        fmt.Println(findDigits(num))
    }
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(1) extra space
func findDigits(num int) int {
    divisors := 0
    
    for originalNumber := num; num != 0; num /= 10 {
        divisor := num % 10
        if divisor != 0 && originalNumber%divisor == 0 {
            divisors++
        }
    }

    return divisors
}
