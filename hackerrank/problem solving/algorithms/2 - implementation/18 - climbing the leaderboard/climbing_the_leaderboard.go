// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    n := readNumbers(reader, 1)[0]
    ranked := removeDuplicates(readNumbers(reader, n))
    n = readNumbers(reader, 1)[0]
    player := readNumbers(reader, n)

    for _, x := range climbingLeaderboard(ranked, player) {
        fmt.Println(x)
    }
}

func readNumbers(reader *bufio.Reader, n int) []int {
    line, _ := reader.ReadString('\n')
    tokens := strings.Fields(line)
    numbers := make([]int, n)
    for i, token := range tokens {
        numbers[i], _ = strconv.Atoi(token)
    }
    return numbers
}

func removeDuplicates(numbers []int) []int {
    deduplicated := []int{numbers[0]}
    for i := 1; i < len(numbers); i++ {
        if numbers[i] != numbers[i-1] {
            deduplicated = append(deduplicated, numbers[i])
        }
    }
    return deduplicated
}

func climbingLeaderboard(ranked, player []int) []int {
    playerRanks := make([]int, len(player))
    i := len(ranked) - 1

    for j, score := range player {
        for i >= 0 && score >= ranked[i] {
            i--
        }
        playerRanks[j] = i + 2
    }

    return playerRanks
}
