// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n1, n2 int
    fmt.Scan(&n1, &n2)
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
    findFactorsOfSetB(potentialFactors, setB)
    return countFactors(potentialFactors)
}

func findNumbersDivisibleBySetA(potentialFactors *[]int, setA []int, firstElementOfSetB int) {
    var last_element_set_a int = setA[len(setA)-1]

    for potentialFactor := last_element_set_a; potentialFactor <= firstElementOfSetB; potentialFactor += last_element_set_a {
        isARealPotentialFactor := true

        for _, x := range setA {
            if potentialFactor%x != 0 {
                isARealPotentialFactor = false
                break
            }
        }

        if isARealPotentialFactor {
            *potentialFactors = append(*potentialFactors, potentialFactor)
        }
    }
}

func findFactorsOfSetB(potentialFactors []int, setB []int) {
    for _, x := range setB {
        for i, potentialFactor := range potentialFactors {
            if potentialFactor != 0 && x%potentialFactor != 0 {
                potentialFactors[i] = 0
            }
        }
    }
}

func countFactors(potentialFactors []int) int {
    nFactors := 0
    for _, x := range potentialFactors {
        if x != 0 {
            nFactors++
        }
    }
    return nFactors
}
