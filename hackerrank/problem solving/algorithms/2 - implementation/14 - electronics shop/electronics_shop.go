// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
    "sort"
)

func main() {
    var budget, nKeyboards, nUsbDrives int
    fmt.Scanf("%d %d %d", &budget, &nKeyboards, &nUsbDrives)
    keyboards := readNumbers(nKeyboards)
    usbDrives := readNumbers(nUsbDrives)
    sort.Ints(keyboards)
    sort.Ints(usbDrives)
    keyboards = slices.Compact(keyboards)
    usbDrives = slices.Compact(usbDrives)
    fmt.Println(calculateMoneySpent(keyboards, usbDrives, budget))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scanf("%d", &numbers[i])
    }
    return numbers
}

func calculateMoneySpent(keyboards []int, usbDrives []int, budget int) int {
    maxSpent := -1
    i := 0
    j := len(usbDrives) - 1

    for i < len(keyboards) && j >= 0 {
        if keyboards[i] >= budget {
            break
        }
        sum := keyboards[i] + usbDrives[j]
        if sum > budget {
            j--
        } else if sum == budget {
            return budget
        } else {
            if sum > maxSpent {
                maxSpent = sum
            }
            i++
        }
    }

    return maxSpent
}
