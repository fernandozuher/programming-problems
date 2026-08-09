// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

type Gifts struct {
    nBlackGifts               int
    nWhiteGifts               int
    blackGiftCost             int
    whiteGiftCost             int
    costToConvertBetweenGifts int
}

func main() {
    n := morfoio.Read[int]()
    for range n {
        fmt.Println(minCostOfBuyingGifts(readTestCase()))
    }
}

func readTestCase() Gifts {
    var x Gifts
    x.nBlackGifts = morfoio.Read[int]()
    x.nWhiteGifts = morfoio.Read[int]()
    x.blackGiftCost = morfoio.Read[int]()
    x.whiteGiftCost = morfoio.Read[int]()
    x.costToConvertBetweenGifts = morfoio.Read[int]()
    return x
}

// T: O(1)
// S: O(1) extra space
func minCostOfBuyingGifts(x Gifts) int {
    blackCost := min(x.blackGiftCost, x.whiteGiftCost+x.costToConvertBetweenGifts)
    whiteCost := min(x.whiteGiftCost, x.blackGiftCost+x.costToConvertBetweenGifts)
    return x.nBlackGifts*blackCost + x.nWhiteGifts*whiteCost
}
