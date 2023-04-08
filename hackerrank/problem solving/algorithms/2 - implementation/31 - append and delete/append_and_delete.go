// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var initialString string = ReadAWord()
    var finalString string = ReadAWord()
    var numberOfOperations int = ReadANumber()

    var response bool = AppendAndDelete(initialString, finalString, numberOfOperations)
    PrintOutput(response)
}

    func ReadAWord() string {
        var word string
        fmt.Scan(&word)
        return word
    }

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func AppendAndDelete(initialString string, finalString string, numberOfOperations int) bool {
        var commonPrefixSizeBetweenStrings int = FindCommonPrefixSizeBetweenStrings(initialString, finalString)

        var sizeOfDifferentCharactersFromInitialString int = len(initialString) - commonPrefixSizeBetweenStrings
        var sizeOfDifferentCharactersFromfinalString int = len(finalString) - commonPrefixSizeBetweenStrings

        var minimalQuantityOfOperationsToReplaceString int = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromfinalString
        numberOfOperations -= minimalQuantityOfOperationsToReplaceString

        return AreOperationsSuitableToReplaceString(numberOfOperations, commonPrefixSizeBetweenStrings)
    }

        func FindCommonPrefixSizeBetweenStrings(initialString string, finalString string) int {
            var size int = 0
            for size != len(initialString) && size != len(finalString) && initialString[size] == finalString[size] {
                size++
            }
            return size
        }

        func AreOperationsSuitableToReplaceString(numberOfOperations int, commonPrefixSizeBetweenStrings int) bool {
            if numberOfOperations < 0 ||
                (AreOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                    AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)) {
                return false
            }
            return true
        }

            func AreOperationsBiggerThanZeroAndOdd(numberOfOperations int) bool {
                return numberOfOperations > 0 && numberOfOperations%2 == 1
            }

            func AreNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations int, commonPrefixSizeBetweenStrings int) bool {
                return numberOfOperations < commonPrefixSizeBetweenStrings*2
            }

    func PrintOutput(response bool) {
        if response {
            fmt.Println("Yes")
        } else {
            fmt.Println("No")
        }
    }
