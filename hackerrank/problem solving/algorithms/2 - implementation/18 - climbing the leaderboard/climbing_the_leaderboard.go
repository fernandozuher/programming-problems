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
    arr := make([]int, n)
    for i, token := range tokens {
        arr[i], _ = strconv.Atoi(token)
    }
    return arr
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(1) extra space
func removeDuplicates(arr []int) []int {
    return slices.Compact(arr)
}

// n1: length of player, playerRanks
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
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
