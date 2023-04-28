# Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

def main
    nTestCases = gets.to_i
    output = Array.new nTestCases

    for i in 0...nTestCases
        input = readATestCase
        output[i] = calculateMinimumCostOfBuyingGifts(input)
    end

    puts output
end

    def readATestCase
        nBlackGifts, nWhiteGifts = readAnIntArray
        blackGiftCost, whiteGiftCost, costToConvertBetweenGifts = readAnIntArray
        [nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts]
    end

        def readAnIntArray
            gets.strip.split.map(&:to_i)
        end

    def calculateMinimumCostOfBuyingGifts input
        if areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts input
            return calculateMinimumStandardCost input
        end
        return calculateMinimumCostInConvertingGifts input
    end

        def areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts input
            _, _, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts = input
            costToConvertFromBlackToWhite = blackGiftCost + costToConvertBetweenGifts
            costToConvertFromWhiteToBlack = whiteGiftCost + costToConvertBetweenGifts

            whiteGiftCost <= costToConvertFromBlackToWhite and blackGiftCost <= costToConvertFromWhiteToBlack
        end

        def calculateMinimumStandardCost input
            nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, _ = input
            nBlackGifts * blackGiftCost + nWhiteGifts * whiteGiftCost
        end

        def calculateMinimumCostInConvertingGifts input
            nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts = input

            costToConvertFromBlackToWhite = blackGiftCost + costToConvertBetweenGifts
            totalGifts = nBlackGifts + nWhiteGifts
            minimumCostOfBuyingGifts = 0

            if whiteGiftCost > costToConvertFromBlackToWhite
                minimumCostOfBuyingGifts = totalGifts * blackGiftCost + nWhiteGifts * costToConvertBetweenGifts
            else
                minimumCostOfBuyingGifts = totalGifts * whiteGiftCost + nBlackGifts * costToConvertBetweenGifts
            end

            minimumCostOfBuyingGifts
        end

main
