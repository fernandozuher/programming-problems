// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var attendees, topics int
    fmt.Scan(&attendees, &topics)
    var binaryStrings []string = readBinaryStrings(attendees)
    var maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects int = findMaximumSubjectsAndTeamsThatKnowThem(binaryStrings)
    fmt.Printf("%d\n%d", maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects)
}

    func readBinaryStrings(n int) []string {
        binaryStrings := make([]string, n)
        for i := range binaryStrings {
            fmt.Scan(&binaryStrings[i])
        }
        return binaryStrings
    }

    func findMaximumSubjectsAndTeamsThatKnowThem(binaryStrings []string) (int, int) {
        maximumSubjectsKnownByTeams := 0
        teamsThatKnowMaximumSubjects := 0

        for i, previous := range binaryStrings[:len(binaryStrings)-1] {
            for _, current := range binaryStrings[i+1:] {
                var subjectsKnownBy2Teams int = countSubjectsKnownBy2Teams(previous, current)
                updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams, &maximumSubjectsKnownByTeams, &teamsThatKnowMaximumSubjects)
            }
        }

        return maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects
    }

        func countSubjectsKnownBy2Teams(binaryString1 string, binaryString2 string) int {
            var subjectsKnownBy2Teams int = 0
            for i := range binaryString1 {
                if binaryString1[i] == '1' || binaryString2[i] == '1' {
                    subjectsKnownBy2Teams += 1
                }
            }
            return subjectsKnownBy2Teams
        }

        func updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams int, maximumSubjectsKnownByTeams *int, teamsThatKnowMaximumSubjects *int) {
            if subjectsKnownBy2Teams > *maximumSubjectsKnownByTeams {
                *maximumSubjectsKnownByTeams = subjectsKnownBy2Teams
                *teamsThatKnowMaximumSubjects = 1
            } else if subjectsKnownBy2Teams == *maximumSubjectsKnownByTeams {
                (*teamsThatKnowMaximumSubjects)++
            }
        }
