// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var inputStrings map[string]int = readInput(n)

    fmt.Scan(&n)
    var result []int = readQueriesAndCountMatches(inputStrings, n)
    printArray(result)
}

    func readInput(n int) map[string]int {
        input := map[string]int{}
        for i, line := 0, ""; i < n; i++ {
            fmt.Scanf("%s", &line)
            input[line] += 1
        }
        return input
    }

    func readQueriesAndCountMatches(input map[string]int, n int) []int {
        result := make([]int, n)
        var query string
        for i := range result {
            fmt.Scanf("%s", &query)
            result[i] = input[query]
        }
        return result
    }

    func printArray(array []int) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
