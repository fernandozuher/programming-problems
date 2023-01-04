// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
    socks := readLineAsIntArray(scanner)

    result := sockMerchant(socks)
    fmt.Print(result)
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

    func sockMerchant(socks []int) int {
        pairs := 0
        socksPairing := make(map[int]bool)

        for _, sock := range socks {
            if socksPairing[sock] {
                pairs++
            }
            socksPairing[sock] = !socksPairing[sock]
        }
        
        return pairs
    }
