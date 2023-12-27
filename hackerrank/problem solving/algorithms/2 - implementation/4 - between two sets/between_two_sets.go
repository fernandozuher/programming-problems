// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n1, n2 int
    fmt.Scan(&n1, &n2);
    setA := readIntArray(n1)
    setB := readIntArray(n2)

    sort.Ints(setA)
    sort.Ints(setB)

    fmt.Print(findTotalFactors(setA, setB))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findTotalFactors(setA []int, setB []int) int {
        var potentialFactors []int

        findNumbersDivisibleBySetA(&potentialFactors, setA, setB[0])
        findFactorsOfSetB(&potentialFactors, setB)
        totalFactors := countFactors(potentialFactors)

        return totalFactors
    }

        func findNumbersDivisibleBySetA(potentialFactors *[]int, setA []int, firstElementOfSetB int) {
            for potentialFactor := setA[len(setA) - 1]; potentialFactor <= firstElementOfSetB; potentialFactor += setA[len(setA) - 1] {
                isARealPotentialFactor := true

                for _, number := range setA {
                    if potentialFactor % number != 0 {
                        isARealPotentialFactor = false
                        break
                    }
                }

                if isARealPotentialFactor == true {
                    *potentialFactors = append(*potentialFactors, potentialFactor)
                }
            }
        }

        func findFactorsOfSetB(potentialFactors *[]int, setB []int) {
            for _, number := range setB {
                for i, potentialFactor := range *potentialFactors {
                    if potentialFactor != 0 && number % potentialFactor != 0 {
                        (*potentialFactors)[i] = 0
                    }
                }
            }
        }

        func countFactors(potentialFactors []int) int {
            var nFactors int = 0

            for _, potentialFactor := range potentialFactors {
                if potentialFactor != 0 {
                    nFactors++
                }
            }

            return nFactors
        }
