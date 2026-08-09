// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "slices"
)

func main() {
    firstLine := morfoio.ReadLn[int]()
    budget := firstLine[0]
    keyboards := preprocessInput(morfoio.ReadLn[int]())
    usbDrives := preprocessInput(morfoio.ReadLn[int]())
    fmt.Println(calcMoneySpent(keyboards, usbDrives, budget))
}

// n: length of arr
// k: length of arr after deduplication
// k <= n
// T: O(n log n)
// S: O(n + k) extra space
func preprocessInput(arr []int) []int {
    slices.Sort(arr)
    arr = slices.Compact(arr)
    return arr
}

// n1: length of keyboards
// n2: length of usbDrives
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
