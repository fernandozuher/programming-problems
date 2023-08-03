// https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

package solution

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    array := make([]int, n)
    for i, _ := range array {
        fmt.Scan(&array[i])
    }

    for i := len(array) - 1; i >= 0; i-- {
        fmt.Printf("%d ", array[i])
    }
}
