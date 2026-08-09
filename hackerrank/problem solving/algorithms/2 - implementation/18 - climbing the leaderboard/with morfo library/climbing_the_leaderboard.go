// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

package main

import (
    "morfo/morfoio"
    "slices"
)

func main() {
    morfoio.SkipInputLn()
    ranked := removeDuplicates(morfoio.ReadLn[int]())

    morfoio.SkipInputLn()
    player := morfoio.ReadLn[int]()

    morfoio.Println(climbingLeaderboard(ranked, player))
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
