// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nTestCases uint64 = ReadANumber()
    var output []uint64 = make([]uint64, nTestCases)

    for i, _ := range output {
        var input = ReadATestCase()
        output[i] = CalculateMinimumCostOfBuyingGifts(input)
    }

    PrintArray(output)
}

    func ReadANumber() uint64 {
        var number uint64
        fmt.Scan(&number)
        return number
    }

    func ReadATestCase() []uint64 {
        nBlackGifts, nWhiteGifts := ReadANumber(), ReadANumber()
        blackGiftCost, whiteGiftCost, costToConvertBetweenGifts := ReadANumber(), ReadANumber(), ReadANumber()

        return []uint64{nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts}
    }

    func CalculateMinimumCostOfBuyingGifts(input []uint64) uint64 {
        if AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input) {
            return CalculateMinimumStandardCost(input)
        }
        return CalculateMinimumCostInConvertingGifts(input)
    }

        func AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input []uint64) bool {
            blackGiftCost, whiteGiftCost, costToConvertBetweenGifts := input[2], input[3], input[4]
            var costToConvertFromBlackToWhite uint64 = blackGiftCost + costToConvertBetweenGifts
            var costToConvertFromWhiteToBlack uint64 = whiteGiftCost + costToConvertBetweenGifts

            return whiteGiftCost <= costToConvertFromBlackToWhite && blackGiftCost <= costToConvertFromWhiteToBlack
        }

        func CalculateMinimumStandardCost(input []uint64) uint64 {
            nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost := input[0], input[1], input[2], input[3]
            return nBlackGifts*blackGiftCost + nWhiteGifts*whiteGiftCost
        }

        func CalculateMinimumCostInConvertingGifts(input []uint64) uint64 {
            nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts := input[0], input[1], input[2], input[3], input[4]

            var costToConvertFromBlackToWhite uint64 = blackGiftCost + costToConvertBetweenGifts
            var totalGifts uint64 = nBlackGifts + nWhiteGifts

            var minimumCostOfBuyingGifts uint64

            if whiteGiftCost > costToConvertFromBlackToWhite {
                minimumCostOfBuyingGifts = totalGifts*blackGiftCost + nWhiteGifts*costToConvertBetweenGifts
            } else {
                minimumCostOfBuyingGifts = totalGifts*whiteGiftCost + nBlackGifts*costToConvertBetweenGifts
            }

            return minimumCostOfBuyingGifts
        }

    func PrintArray(array []uint64) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
