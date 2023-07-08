// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

package solution

import "math"

func Solution(n int) int {
    longestBinaryGap := 0

    for number := reduceNumberUntilFirst10(n); number > 0; number = reduceNumberUntilFirst10(number) {
        tempLongestBinaryGap := 0

        var number int = countBinaryGapInParameterAndReturnReducedNumber(&tempLongestBinaryGap, number)

        if isNotReducedNumber0(number) {
            longestBinaryGap = int(math.Max(float64(tempLongestBinaryGap), float64(longestBinaryGap)))
        }
    }

    return longestBinaryGap
}

    func reduceNumberUntilFirst10(number int) int {
        for number != 0 && isNumberDivisibleBy2(number) {
            number /= 2
        }

        for number != 0 && !isNumberDivisibleBy2(number) {
            number /= 2
        }

        return number
    }

    func countBinaryGapInParameterAndReturnReducedNumber(tempLongestBinaryGap *int, number int) int {
        for number != 0 && isNumberDivisibleBy2(number) {
            (*tempLongestBinaryGap)++
            number /= 2
        }
        return number
    }

        func isNumberDivisibleBy2(number int) bool {
            return number%2 == 0
        }

    func isNotReducedNumber0(number int) bool {
        return number != 0
    }
