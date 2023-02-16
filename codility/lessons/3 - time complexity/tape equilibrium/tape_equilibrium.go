// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

package solution

import "math"


func Solution(array []int) int {
    var minimumDifferenceBetweenParts int = FindMinimumDifferenceBetweenTwoPartsArray(array)
    return minimumDifferenceBetweenParts
}

    func FindMinimumDifferenceBetweenTwoPartsArray(array []int) int {
        var firstPart int = array[0]
        var secondPart int = SumArrayElements(array) - firstPart
        var minimumDifferenceBetweenParts int = int(math.Abs(float64(firstPart) - float64(secondPart)))

        for _, number := range array[1 : len(array)-1] {
            firstPart += number
            secondPart -= number
            var currentMinimum int = int(math.Abs(float64(firstPart) - float64(secondPart)))

            if minimumDifferenceBetweenParts > currentMinimum {
                minimumDifferenceBetweenParts = currentMinimum
            }
        }

        return minimumDifferenceBetweenParts
    }

        func SumArrayElements(array []int) int {
            var sum int = 0
            for i := 0; i < len(array); i++ {
                sum += array[i]
            }
            return sum
        }
