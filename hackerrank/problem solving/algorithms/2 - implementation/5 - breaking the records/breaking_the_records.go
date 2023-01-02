// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    readLineAsIntArray(scanner)
    setA := readLineAsIntArray(scanner)

    result := breakingRecords(setA)
    fmt.Print(result[0], result[1])
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

    func breakingRecords(scores []int) [2]int {
        most_points, breaking_most_points_records := scores[0], 0
        least_points, breaking_least_points_records := scores[0], 0

        for _, score := range scores {
            if score > most_points {
                most_points = score
                breaking_most_points_records++
            } else if score < least_points {
                least_points = score
                breaking_least_points_records++
            }
        }

        records := [2]int{breaking_most_points_records, breaking_least_points_records}
        return records
    }
