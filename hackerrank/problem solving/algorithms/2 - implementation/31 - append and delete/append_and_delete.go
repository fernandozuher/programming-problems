// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var initialString, finalString string
    var operations int
    fmt.Scan(&initialString, &finalString, &operations)

    if appendAndDelete(initialString, finalString, operations) == true {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

    func appendAndDelete(initialString string, finalString string, operations int) bool {
        var commonPrefixSizeBetweenStrings int = findCommonPrefixSizeBetweenStrings(initialString, finalString)

        var sizeOfDifferentCharactersFromInitialString int = len(initialString) - commonPrefixSizeBetweenStrings
        var sizeOfDifferentCharactersFromfinalString int = len(finalString) - commonPrefixSizeBetweenStrings

        var minimalQuantityOfOperationsToReplaceString int = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromfinalString
        operations -= minimalQuantityOfOperationsToReplaceString

        return areOperationsSuitableToReplaceString(operations, commonPrefixSizeBetweenStrings)
    }

        func findCommonPrefixSizeBetweenStrings(initialString string, finalString string) int {
            var size int = 0
            n := int(math.Min(float64(len(initialString)), float64(len(finalString))))
            for ; n > 0 && initialString[size] == finalString[size]; n-- {
                size++
            }
            return size
        }

        func areOperationsSuitableToReplaceString(operations int, commonPrefixSizeBetweenStrings int) bool {
            if operations < 0 ||
                (areOperationsBiggerThanZeroAndOdd(operations) &&
                    areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(operations, commonPrefixSizeBetweenStrings)) {
                return false
            }
            return true
        }

            func areOperationsBiggerThanZeroAndOdd(operations int) bool {
                return operations > 0 && operations%2 == 1
            }

            func areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(operations int, commonPrefixSizeBetweenStrings int) bool {
                return operations < commonPrefixSizeBetweenStrings*2
            }
