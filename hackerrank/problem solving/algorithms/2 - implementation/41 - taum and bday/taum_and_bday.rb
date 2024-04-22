# Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

def main
    nTestCases = gets.to_i
    output = Array.new nTestCases

    for i in 0...nTestCases
        input = readATestCase
        obj = TaumAndBday.new(input)
        output[i] = obj.getMinimumCostOfBuyingGifts
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

    class TaumAndBday
        @nBlackGifts
        @nWhiteGifts
        @blackGiftCost
        @whiteGiftCost
        @costToConvertBetweenGifts

        @costToConvertFromBlackToWhite
        @costToConvertFromWhiteToBlack

        @minimumCostOfBuyingGifts

        def initialize input
            @nBlackGifts, @nWhiteGifts, @blackGiftCost, @whiteGiftCost, @costToConvertBetweenGifts = input

            @costToConvertFromBlackToWhite = @blackGiftCost + @costToConvertBetweenGifts
            @costToConvertFromWhiteToBlack = @whiteGiftCost + @costToConvertBetweenGifts

            @minimumCostOfBuyingGifts = _calculateMinimumCostOfBuyingGifts
        end

            def _calculateMinimumCostOfBuyingGifts
                if _areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts
                    return _calculateMinimumStandardCost
                end
                return _calculateMinimumCostInConvertingGifts
            end

                def _areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts
                    @whiteGiftCost <= @costToConvertFromBlackToWhite && @blackGiftCost <= @costToConvertFromWhiteToBlack
                end

                def _calculateMinimumStandardCost
                    @nBlackGifts * @blackGiftCost + @nWhiteGifts * @whiteGiftCost
                end

                def _calculateMinimumCostInConvertingGifts
                    totalGifts = @nBlackGifts + @nWhiteGifts

                    if @whiteGiftCost > @costToConvertFromBlackToWhite
                        return totalGifts * @blackGiftCost + @nWhiteGifts * @costToConvertBetweenGifts
                    else
                        return totalGifts * @whiteGiftCost + @nBlackGifts * @costToConvertBetweenGifts
                    end
                end

        def getMinimumCostOfBuyingGifts
            @minimumCostOfBuyingGifts
        end
    end

main
