// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, page int
    _, _ = fmt.Scan(&n, &page)
    fmt.Println(pageCount(n, page))
}

// T: O(1)
// S: O(1) extra space
func pageCount(n, page int) int {
    fromFront := page / 2
    fromBack := n/2 - fromFront
    return min(fromFront, fromBack)
}
