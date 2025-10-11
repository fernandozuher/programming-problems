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
        testCase := readTestCase()
        fmt.Println(minCostOfBuyingGifts(testCase))
    }
}

func readTestCase() Gifts {
    var x Gifts
    _, _ = fmt.Scan(&x.nBlackGifts, &x.nWhiteGifts, &x.blackGiftCost, &x.whiteGiftCost, &x.costToConvertBetweenGifts)
    return x
}

func minCostOfBuyingGifts(gifts Gifts) int {
    blackCost := min(gifts.blackGiftCost, gifts.whiteGiftCost+gifts.costToConvertBetweenGifts)
    whiteCost := min(gifts.whiteGiftCost, gifts.blackGiftCost+gifts.costToConvertBetweenGifts)
    return gifts.nBlackGifts*blackCost + gifts.nWhiteGifts*whiteCost
}
