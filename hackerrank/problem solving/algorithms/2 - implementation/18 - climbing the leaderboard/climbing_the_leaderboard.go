// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int

    fmt.Scan(&n)
    var ranked []int = readIntArray(n)
    ranked = removeDuplicates(ranked)

    fmt.Scan(&n)
    var player []int = readIntArray(n)

    printArray(climbingLeaderboard(ranked, player))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func removeDuplicates(array []int) []int {
        var newSize int = 0

        for i := 0; i < len(array)-1; i++ {
            if array[i] != array[i+1] {
                array[newSize] = array[i]
                newSize++
            }
        }

        array[newSize] = array[len(array)-1]
        newSize++
        return array[:newSize]
    }

    func climbingLeaderboard(ranked []int, player []int) []int {
        var playerRank []int = make([]int, len(player))

        for i, lastIndex, n := 0, len(ranked)-1, len(player); i < n; i++ {
            var index int = binarySearchDescendingOrder(ranked, 0, lastIndex, player[i])
            playerRank[i] = index + 1
        }

        return playerRank
    }

        func binarySearchDescendingOrder(array []int, low int, high int, key int) int {
            if high >= low {
                var middle int = low + (high-low)/2

                if key == array[middle] {
                    return middle
                } else if key > array[middle] {
                    return binarySearchDescendingOrder(array, low, middle-1, key)
                } else {
                    return binarySearchDescendingOrder(array, middle+1, high, key)
                }
            }
            return low
        }

    func printArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
