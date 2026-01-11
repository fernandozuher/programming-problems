// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "slices"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    n := readNumbers(reader, 1)[0]
    ranked := slices.Compact(readNumbers(reader, n))
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

// n: length of array player|playerRanks
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
func climbingLeaderboard(ranked, player []int) []int {
    playerRanks := make([]int, len(player))
    seeker := len(ranked) - 1

    for writer, score := range player {
        for seeker >= 0 && score >= ranked[seeker] {
            seeker--
        }
        playerRanks[writer] = seeker + 2
    }

    return playerRanks
}
