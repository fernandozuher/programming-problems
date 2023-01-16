// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

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

    var inputLine []int = readLineAsIntArray(scanner)
    var maximumHeightCanJump int = inputLine[1]

    hurdlesHeights := readLineAsIntArray(scanner)

    var result int = hurdleRace(hurdlesHeights, maximumHeightCanJump)
    fmt.Print(result)
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
        var line string

        if scanner.Scan() {
            line = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        inputStringArray := strings.Split(line, " ")
        inputLine := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            checkError(err)
            inputLine[i] = number
        }
        return inputLine
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func hurdleRace(hurdlesHeights []int, maximumHeightCanJump int) int {
        highestHurdle := 0
        doses := 0

        for _, hurdleHeight := range hurdlesHeights {
            if highestHurdle < hurdleHeight {
                highestHurdle = hurdleHeight
            }
        }

        if highestHurdle > maximumHeightCanJump {
            doses = highestHurdle - maximumHeightCanJump
        } else {
            doses = 0
        }

        return doses
    }
