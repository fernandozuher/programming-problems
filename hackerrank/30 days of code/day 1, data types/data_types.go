// https://www.hackerrank.com/challenges/30-data-types/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    const i uint64 = 4
    const d float64 = 4.0
    const s string = "HackerRank "

    scanner := bufio.NewScanner(os.Stdin)

    scanner.Scan()
    i2, _ := strconv.ParseUint(scanner.Text(), 10, 64)
    scanner.Scan()
    d2, _ := strconv.ParseFloat(scanner.Text(), 64)
    scanner.Scan()
    s2 := scanner.Text()

    fmt.Println(i + i2)
    fmt.Printf("%.1f\n", d+d2)
    fmt.Println(s + s2)
}
