# Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

def main():

    N_TEST_CASES = int(input())
    output = [None] * N_TEST_CASES

    for i in range(N_TEST_CASES):
        INPUT = readATestCase()
        OBJ = TaumAndBday(INPUT)
        output[i] = OBJ.getMinimumCostOfBuyingGifts()

    print(*output, sep="\n")


def readATestCase():

    N_BLACK_GIFTS, N_WHITE_GIFTS = readAnIntArray()
    BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS = readAnIntArray()
    return [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS]


def readAnIntArray():

    return list(map(int, input().split()))


class TaumAndBday:

    def __init__(self, INPUT):

        self.__nBlackGifts, self.__nWhiteGifts, self.__blackGiftCost, self.__whiteGiftCost, self.__costToConvertBetweenGifts = INPUT

        self.__costToConvertFromBlackToWhite = self.__blackGiftCost + self.__costToConvertBetweenGifts
        self.__costToConvertFromWhiteToBlack = self.__whiteGiftCost + self.__costToConvertBetweenGifts

        self.__minimumCostOfBuyingGifts = self.__calculateMinimumCostOfBuyingGifts()


    def __calculateMinimumCostOfBuyingGifts(self):

        if self.__areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts():
            return self.__calculateMinimumStandardCost()

        return self.__calculateMinimumCostInConvertingGifts()


    def __areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(self):

        return self.__whiteGiftCost <= self.__costToConvertFromBlackToWhite and self.__blackGiftCost <= self.__costToConvertFromWhiteToBlack


    def __calculateMinimumStandardCost(self):

        return self.__nBlackGifts * self.__blackGiftCost + self.__nWhiteGifts * self.__whiteGiftCost


    def __calculateMinimumCostInConvertingGifts(self):

        TOTAL_GIFTS = self.__nBlackGifts + self.__nWhiteGifts

        if self.__whiteGiftCost > self.__costToConvertFromBlackToWhite:
            return TOTAL_GIFTS * self.__blackGiftCost + self.__nWhiteGifts * self.__costToConvertBetweenGifts

        return TOTAL_GIFTS * self.__whiteGiftCost + self.__nBlackGifts * self.__costToConvertBetweenGifts


    def getMinimumCostOfBuyingGifts(self):

        return self.__minimumCostOfBuyingGifts


if __name__ == "__main__":
    main()
