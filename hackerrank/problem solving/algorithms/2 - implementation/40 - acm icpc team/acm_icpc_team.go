// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var attendees uint32 = ReadANumber()
    var _ uint32 = ReadANumber()
    var binaryStrings []string = ReadBinaryStrings(attendees)

    var output [2]uint32 = FindMaximumSubjectsAndTeamsThatKnowThem(binaryStrings)
    PrintArray(output)
}

    func ReadANumber() uint32 {
        var number uint32
        fmt.Scan(&number)
        return number
    }

    func ReadBinaryStrings(nStrings uint32) []string {
        var binaryStrings []string = make([]string, nStrings)

        for i, _ := range binaryStrings {
            fmt.Scan(&binaryStrings[i])
        }

        return binaryStrings
    }

    func FindMaximumSubjectsAndTeamsThatKnowThem(binaryStrings []string) [2]uint32 {
        var maximumSubjectsKnownByTeams uint32 = 0
        var teamsThatKnowMaximumSubjects uint32 = 0

        for i := 0; i < len(binaryStrings)-1; i++ {
            for j := (i + 1); j < len(binaryStrings); j++ {
                var subjectsKnownBy2Teams uint32 = CountSubjectsKnownBy2Teams(binaryStrings[i], binaryStrings[j])
                UpdateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams, &maximumSubjectsKnownByTeams, &teamsThatKnowMaximumSubjects)
            }
        }

        var output [2]uint32 = [2]uint32{maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects}
        return output
    }

        func CountSubjectsKnownBy2Teams(binaryString1 string, binaryString2 string) uint32 {
            var subjectsKnownBy2Teams uint32 = 0

            for i := 0; i < len(binaryString1); i++ {
                if binaryString1[i] == '1' || binaryString2[i] == '1' {
                    subjectsKnownBy2Teams += 1
                }
            }

            return subjectsKnownBy2Teams
        }

        func UpdateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams uint32, maximumSubjectsKnownByTeams *uint32, teamsThatKnowMaximumSubjects *uint32) {
            if subjectsKnownBy2Teams > *maximumSubjectsKnownByTeams {
                *maximumSubjectsKnownByTeams = subjectsKnownBy2Teams
                *teamsThatKnowMaximumSubjects = 1
            } else if subjectsKnownBy2Teams == *maximumSubjectsKnownByTeams {
                (*teamsThatKnowMaximumSubjects)++
            }
        }

    func PrintArray(array [2]uint32) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
