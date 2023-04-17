// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var inputString string = ReadAString()
    var nCharacters uint64 = ReadANumber()

    var quantityOfA uint64 = FindQuantityOfAInRepeatedString(inputString, nCharacters)
    fmt.Println(quantityOfA)
}

    func ReadAString() string {
        var inputString string
        fmt.Scan(&inputString)
        return inputString
    }

    func ReadANumber() uint64 {
        var number uint64
        fmt.Scan(&number)
        return number
    }

    func FindQuantityOfAInRepeatedString(inputString string, nCharacters uint64) uint64 {
        var quantityOfA uint64 = FindQuantityOfAInString(inputString)
        quantityOfA *= FindQuantityOfRepeatedEntireString(nCharacters, uint64(len(inputString)))
        quantityOfA += FindQuantityOfRemainingA(nCharacters, inputString)

        return quantityOfA
    }

        func FindQuantityOfAInString(inputString string) uint64 {
            var quantityOfA uint64 = 0

            for _, character := range inputString {
                if character == 'a' {
                    quantityOfA++
                }
            }

            return quantityOfA
        }

        func FindQuantityOfRepeatedEntireString(nCharacters uint64, sizeString uint64) uint64 {
            var nStrings uint64 = nCharacters / sizeString
            return nStrings
        }

        func FindQuantityOfRemainingA(nCharacters uint64, inputString string) uint64 {
            var nRemainingCharactersOfString uint64 = nCharacters % uint64(len(inputString))

            if nRemainingCharactersOfString == 0 {
                return 0
            }

            var subString string = inputString[0:nRemainingCharactersOfString]
            return FindQuantityOfAInString(subString)
        }
