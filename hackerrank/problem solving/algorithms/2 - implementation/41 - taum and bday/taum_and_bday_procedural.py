# Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

def main():

    N_TEST_CASES = int(input())
    output = [None] * N_TEST_CASES

    for i in range(N_TEST_CASES):
        INPUT = readATestCase()
        output[i] = calculateMinimumCostOfBuyingGifts(INPUT)

    print(*output, sep="\n")


def readATestCase():

    N_BLACK_GIFTS, N_WHITE_GIFTS = readAnIntArray()
    BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS = readAnIntArray()
    return [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS]


def readAnIntArray():

    return list(map(int, input().split()))


def calculateMinimumCostOfBuyingGifts(INPUT):

    if areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(INPUT):
        return calculateMinimumStandardCost(INPUT)

    return calculateMinimumCostInConvertingGifts(INPUT)


def areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(INPUT):

    [_, _, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS] = INPUT
    COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS
    COST_TO_CONVERT_FROM_WHITE_TO_BLACK = WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS

    return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE and BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK


def calculateMinimumStandardCost(INPUT):

    [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, _] = INPUT
    return N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST


def calculateMinimumCostInConvertingGifts(INPUT):

    [N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS] = INPUT

    COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS
    TOTAL_GIFTS = N_BLACK_GIFTS + N_WHITE_GIFTS
    minimumCostOfBuyingGifts = 0

    if WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE:
        minimumCostOfBuyingGifts = TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS
    else:
        minimumCostOfBuyingGifts = TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS

    return minimumCostOfBuyingGifts


if __name__ == "__main__":
    main()
