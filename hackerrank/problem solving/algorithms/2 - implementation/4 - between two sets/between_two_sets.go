// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    readLineAsIntArray(scanner)
    setA := readLineAsIntArray(scanner)
    setB := readLineAsIntArray(scanner)

    sort.Ints(setA)
    sort.Ints(setB)

    total := getTotalX(setA, setB)
    fmt.Print(total)
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
        var inputLine string
        
        if scanner.Scan() {
            inputLine = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        inputStringArray := strings.Split(inputLine, " ")
        numbers := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            checkError(err)
            numbers[i] = number
        }
        return numbers
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func getTotalX(setA []int, setB []int) int {
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