// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, m int
    _, _ = fmt.Scan(&n, &m)
    binaries := readBinaries(n)
    maxSubjects, teamsWithMax := acmTeam(binaries)
    fmt.Println(maxSubjects)
    fmt.Println(teamsWithMax)
}

func readBinaries(n int) []string {
    arr := make([]string, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func acmTeam(binaries []string) (int, int) {
    maxSubjects := 0
    teamsWithMax := 0

    for i, a := range binaries[:len(binaries)-1] {
        for _, b := range binaries[i+1:] {
            knownSubjects := countSubjectsKnownBy2Teams(a, b)

            if knownSubjects > maxSubjects {
                maxSubjects = knownSubjects
                teamsWithMax = 1
            } else if knownSubjects == maxSubjects {
                teamsWithMax++
            }
        }
    }

    return maxSubjects, teamsWithMax
}

func countSubjectsKnownBy2Teams(a, b string) int {
    count := 0
    for i := range a {
        if a[i] == '1' || b[i] == '1' {
            count++
        }
    }
    return count
}
