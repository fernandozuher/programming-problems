// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "strconv"
)

func main() {
    var lowerLimit int = ReadANumber()
    var upperLimit int = ReadANumber()

    var output []int = FindKaprekarNumbersInRange(lowerLimit, upperLimit)
    PrintOutput(output)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func FindKaprekarNumbersInRange(lowerLimit int, upperLimit int) []int {
        var kaprekarNumbers []int

        for number := lowerLimit; number <= upperLimit; number++ {
            var potentialKaprekarNumber int = CalculatePotentialKaprekarNumber(number)
            if number == potentialKaprekarNumber {
                kaprekarNumbers = append(kaprekarNumbers, number)
            }
        }

        return kaprekarNumbers
    }

        func CalculatePotentialKaprekarNumber(number int) int {
            var squareNumber uint64 = uint64(math.Pow(float64(number), 2))
            var squareNumberInString string = strconv.FormatUint(squareNumber, 10)
            var lengthOfNumberInString int = len(strconv.FormatUint(uint64(number), 10))

            var leftNumberInString string = GetLeftNumberInString(squareNumberInString, lengthOfNumberInString)
            var rightNumberInString string = GetRightNumberInString(squareNumberInString, lengthOfNumberInString)

            var potentialKaprekarNumber int = SumNumbersInStrings(leftNumberInString, rightNumberInString)

            return potentialKaprekarNumber
        }

            func GetLeftNumberInString(squareNumberInString string, lengthOfNumberInString int) string {
                var digitsToSkip int = 0
                var digitsToTake int = len(squareNumberInString) - lengthOfNumberInString
                var numberInString string = squareNumberInString[digitsToSkip:digitsToTake]
                return numberInString
            }

            func GetRightNumberInString(squareNumberInString string, lengthOfNumberInString int) string {
                var digitsToSkip int = len(squareNumberInString) - lengthOfNumberInString
                var numberInString string = squareNumberInString[digitsToSkip:]
                return numberInString
            }

            func SumNumbersInStrings(leftNumberInString string, rightNumberInString string) int {
                if len(leftNumberInString) > 0 && len(rightNumberInString) > 0 {
                    num1, _ := strconv.Atoi(leftNumberInString)
                    num2, _ := strconv.Atoi(rightNumberInString)
                    return num1 + num2

                } else if len(leftNumberInString) == 0 {
                    num, _ := strconv.Atoi(rightNumberInString)
                    return num

                } else if len(rightNumberInString) == 0 {
                    num, _ := strconv.Atoi(leftNumberInString)
                    return num
                }

                return 0
            }

    func PrintOutput(array []int) {
        if len(array) > 0 {
            for _, element := range array {
                fmt.Printf("%d ", element)
            }
        } else {
            fmt.Println("INVALID RANGE")
        }
    }
