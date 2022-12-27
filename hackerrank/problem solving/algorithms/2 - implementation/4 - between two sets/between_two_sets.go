// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "sort"
    "strconv"
    "strings"
)

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

func main() {
    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)
    defer stdout.Close()
    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)
    readLineAsIntArray(reader)
    setA := readLineAsIntArray(reader)
    setB := readLineAsIntArray(reader)

    sort.Ints(setA)
    sort.Ints(setB)

    total := getTotalX(setA, setB)
    fmt.Fprintf(writer, "%d\n", total)
    writer.Flush()
}

    func readLineAsIntArray(reader *bufio.Reader) []int {
        
        inputStringArray := strings.Split(readLine(reader), " ")
        numbers := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            if err != nil {
                panic(err)
            }
            numbers[i] = number
        }
        return numbers
    }

        func readLine(reader *bufio.Reader) string {
            str, _, err := reader.ReadLine()
            if err == io.EOF {
                return ""
            }

            return strings.TrimRight(string(str), "\r\n")
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