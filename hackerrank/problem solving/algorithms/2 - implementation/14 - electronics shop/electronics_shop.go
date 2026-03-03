// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var budget, nKeyboards, nUsbDrives int
    _, _ = fmt.Scan(&budget, &nKeyboards, &nUsbDrives)
    keyboards := preprocessInput(readNumbers(nKeyboards))
    usbDrives := preprocessInput(readNumbers(nUsbDrives))
    fmt.Println(calcMoneySpent(keyboards, usbDrives, budget))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array arr
// k: length after deduplication
// k <= n
// T: O(n + k log k) = O(n log n)
// S: O(k) = O(n) extra space
func preprocessInput(arr []int) []int {
    data := map[int]bool{}
    var out []int

    for _, x := range arr {
        if _, ok := data[x]; !ok {
            data[x] = true
            out = append(out, x)
        }
    }

    slices.Sort(out)
    return out
}

// n1: length of array keyboards
// n2: length of array usbDrives
// T: O(n1 + n2)
// S: O(1) extra space
func calcMoneySpent(keyboards, usbDrives []int, budget int) int {
    if keyboards[0] >= budget || usbDrives[0] >= budget {
        return -1
    }

    maxSpent := -1
    for idxK, idxUD := 0, len(usbDrives)-1; idxK < len(keyboards) && idxUD >= 0; {
        if keyboards[idxK] >= budget {
            break
        }

        currentSum := keyboards[idxK] + usbDrives[idxUD]
        if currentSum == budget {
            return budget
        }
        if currentSum > budget {
            idxUD -= 1
        } else {
            maxSpent = max(maxSpent, currentSum)
            idxK += 1
        }
    }

    return maxSpent
}
