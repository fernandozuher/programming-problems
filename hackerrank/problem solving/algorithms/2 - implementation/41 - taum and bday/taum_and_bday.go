// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

package main

import "fmt"

type Gifts struct {
    nBlackGifts               int
    nWhiteGifts               int
    blackGiftCost             int
    whiteGiftCost             int
    costToConvertBetweenGifts int
}

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    for range n {
        fmt.Println(minCostOfBuyingGifts(readTestCase()))
    }
}

func readTestCase() Gifts {
    var x Gifts
    _, _ = fmt.Scan(&x.nBlackGifts, &x.nWhiteGifts, &x.blackGiftCost, &x.whiteGiftCost, &x.costToConvertBetweenGifts)
    return x
}

func minCostOfBuyingGifts(x Gifts) int {
    blackCost := min(x.blackGiftCost, x.whiteGiftCost+x.costToConvertBetweenGifts)
    whiteCost := min(x.whiteGiftCost, x.blackGiftCost+x.costToConvertBetweenGifts)
    return x.nBlackGifts*blackCost + x.nWhiteGifts*whiteCost
}
