// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

package solution

import "math"

func Solution(array []int) int {
    var firstPart int = array[0]
    var secondPart int = sumArrayElements(array) - firstPart
    var minimumDifferenceBetweenParts int = intAbs(firstPart, secondPart)

    for _, element := range array[1 : len(array)-1] {
        firstPart += element
        secondPart -= element
        var currentMinimum int = intAbs(firstPart, secondPart)
        minimumDifferenceBetweenParts = intMin(minimumDifferenceBetweenParts, currentMinimum)
    }

    return minimumDifferenceBetweenParts
}

    func sumArrayElements(array []int) int {
        sum := 0
        for _, element := range array {
            sum += element
        }
        return sum
    }

    func intAbs(num1 int, num2 int) int {
        return int(math.Abs(float64(num1) - float64(num2)))
    }

    func intMin(num1 int, num2 int) int {
        return int(math.Min(float64(num1), float64(num2)))
    }
