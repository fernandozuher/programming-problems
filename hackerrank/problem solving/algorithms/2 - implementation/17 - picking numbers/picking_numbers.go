// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(pickingNumbers(readNumbers(n)))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func pickingNumbers(numbers []int) int {
    counter := make(map[int]int)
    for _, num := range numbers {
        counter[num]++
    }

    maxLen := 0
    for num, count := range counter {
        current := count + counter[num+1]
        maxLen = max(maxLen, current)
    }

    return maxLen
}
