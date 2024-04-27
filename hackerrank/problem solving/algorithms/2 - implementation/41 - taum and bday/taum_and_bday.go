// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

package main

import "fmt"

type Gifts struct {
    nBlackGifts               int64
    nWhiteGifts               int64
    blackGiftCost             int64
    whiteGiftCost             int64
    costToConvertBetweenGifts int64
}

func main() {
    var n int32
    _, err := fmt.Scan(&n)
    if err != nil {
        return
    }
    output := make([]int64, n)

    for i := range output {
        output[i] = calculateMinimumCostOfBuyingGifts(readTestCase())
    }
    printArray(output)
}

    func readTestCase() Gifts {
        var x Gifts
        _, err := fmt.Scan(&x.nBlackGifts, &x.nWhiteGifts, &x.blackGiftCost, &x.whiteGiftCost, &x.costToConvertBetweenGifts)
        if err != nil {
            return Gifts{}
        }
        return x
    }

    func calculateMinimumCostOfBuyingGifts(x Gifts) int64 {
        if areOriginalCostsCheaperOrEqualThanConversionBetweenGifts(x) {
            return calculateMinimumStandardCost(x)
        }
        return calculateMinimumCostInConvertingGifts(x)
    }

        func areOriginalCostsCheaperOrEqualThanConversionBetweenGifts(x Gifts) bool {
            var costToConvertFromBlackToWhite int64 = x.blackGiftCost + x.costToConvertBetweenGifts
            var costToConvertFromWhiteToBlack int64 = x.whiteGiftCost + x.costToConvertBetweenGifts
            return x.whiteGiftCost <= costToConvertFromBlackToWhite && x.blackGiftCost <= costToConvertFromWhiteToBlack
        }

        func calculateMinimumStandardCost(x Gifts) int64 {
            return x.nBlackGifts*x.blackGiftCost + x.nWhiteGifts*x.whiteGiftCost
        }

        func calculateMinimumCostInConvertingGifts(x Gifts) int64 {
            var costToConvertFromBlackToWhite int64 = x.blackGiftCost + x.costToConvertBetweenGifts
            var totalGifts int64 = x.nBlackGifts + x.nWhiteGifts

            if x.whiteGiftCost > costToConvertFromBlackToWhite {
                return totalGifts*x.blackGiftCost + x.nWhiteGifts*x.costToConvertBetweenGifts
            }
            return totalGifts*x.whiteGiftCost + x.nBlackGifts*x.costToConvertBetweenGifts
        }

    func printArray(array []int64) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
