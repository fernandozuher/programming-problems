// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

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
    var ranked []int = readLineAsIntArray(scanner)

    readLineAsIntArray(scanner)
    var player []int = readLineAsIntArray(scanner)

    ranked = removeDuplicatesFromRankedArray(ranked)

    var result []int = climbingLeaderboard(ranked, player)
    printResult(result)
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

    func removeDuplicatesFromRankedArray(ranked []int) []int {
        set := make(map[int]int)

        for _, element := range ranked {
            set[element] = element
        }

        var deduplicated_ranked []int = make([]int, len(set))

        i := 0
        for key, _ := range set {
            deduplicated_ranked[i] = key
            i++
        }

        sort.Sort(sort.Reverse(sort.IntSlice(deduplicated_ranked)))

        return deduplicated_ranked
    }

    func climbingLeaderboard(ranked []int, player []int) []int {
        var playerRank []int = make([]int, len(player))

        for i, n, lastIndex := 0, len(player), len(ranked)-1; i < n; i++ {
            var index int = binarySearchDescendingOrder(ranked, 0, lastIndex, player[i])
            playerRank[i] = index + 1
        }

        return playerRank
    }

        func binarySearchDescendingOrder(ranked []int, low int, high int, key int) int {
            if high >= low {
                var middle int = low + (high-low)/2

                if key == ranked[middle] {
                    return middle
                } else if key > ranked[middle] {
                    return binarySearchDescendingOrder(ranked, low, middle-1, key)
                } else {
                    return binarySearchDescendingOrder(ranked, middle+1, high, key)
                }
            }
            return low
        }

    func printResult(result []int) {
        for _, number := range result {
            fmt.Println(number)
        }
    }
