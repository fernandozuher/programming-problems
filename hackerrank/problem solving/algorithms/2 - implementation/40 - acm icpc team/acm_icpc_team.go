// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var attendees uint32 = ReadANumber()
    var _ uint32 = ReadANumber()
    var binaryStrings []string = ReadBinaryStrings(attendees)

    var output [2]uint32 = AcmTeam(binaryStrings)
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

    func AcmTeam(binaryStrings []string) [2]uint32 {
        var teamsThatKnowMaximumSubjects uint32 = 0
        var maximumSubjectsKnownByTeams uint32 = 0

        for i := 0; i < len(binaryStrings)-1; i++ {
            for j := (i + 1); j < len(binaryStrings); j++ {
                var temporaryMaximumSubjectsKnownByTeams uint32 = CalculateMaximumSubjectsKnownByTeam(binaryStrings[i], binaryStrings[j])

                if temporaryMaximumSubjectsKnownByTeams > maximumSubjectsKnownByTeams {
                    maximumSubjectsKnownByTeams = temporaryMaximumSubjectsKnownByTeams
                    teamsThatKnowMaximumSubjects = 1
                } else if temporaryMaximumSubjectsKnownByTeams == maximumSubjectsKnownByTeams {
                    teamsThatKnowMaximumSubjects += 1
                }
            }
        }

        var output [2]uint32 = [2]uint32{maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects}
        return output
    }

        func CalculateMaximumSubjectsKnownByTeam(binaryString1 string, binaryString2 string) uint32 {
            var temporaryMaximumSubjectsKnownByTeams uint32 = 0

            for i := 0; i < len(binaryString1); i++ {
                if binaryString1[i] == '1' || binaryString2[i] == '1' {
                    temporaryMaximumSubjectsKnownByTeams += 1
                }
            }

            return temporaryMaximumSubjectsKnownByTeams
        }

    func PrintArray(array [2]uint32) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
