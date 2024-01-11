// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var pageQuantity, page int
    fmt.Scan(&pageQuantity, &page)
    fmt.Println(pageCount(pageQuantity, page))
}

    func pageCount(pageQuantity int, page int) int {
        var turnOfPagesFromFront int = calculateTurnOfPages(page)
        var maximumTurns int = calculateTurnOfPages(pageQuantity)
        var turnOfPagesFromBack int = maximumTurns - turnOfPagesFromFront
        var minimumTurnOfPages int = int(math.Min(float64(turnOfPagesFromFront), float64(turnOfPagesFromBack)))
        return minimumTurnOfPages
    }

        func calculateTurnOfPages(page int) int {
            if page&1 == 1 {
                return pageIsOdd(page)
            } else {
                return pageIsEven(page)
            }
        }

            func pageIsOdd(page int) int {
                return (page - 1) / 2
            }

            func pageIsEven(page int) int {
                return page / 2
            }
