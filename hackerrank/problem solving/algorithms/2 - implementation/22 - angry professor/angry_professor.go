// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    cancelledClasses := make([]bool, n)

    for i := range cancelledClasses {
        var nStudentsArrivalTime, cancellationThreshold int
        fmt.Scan(&nStudentsArrivalTime, &cancellationThreshold)
        var studentsArrivalTime []int = readIntArray(nStudentsArrivalTime)
        cancelledClasses[i] = angryProfessor(studentsArrivalTime, cancellationThreshold)
    }

    printFormattedOutput(cancelledClasses)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func angryProfessor(studentsArrivalTime []int, cancellationThreshold int) bool {
        var cancelledClass bool = countEarlyArrivalTime(studentsArrivalTime) < cancellationThreshold
        return cancelledClass
    }

        func countEarlyArrivalTime(studentsArrivalTime []int) int {
            earlyArrivalTimeCount := 0

            for _, arrivalTime := range studentsArrivalTime {
                if arrivalTime <= 0 {
                    earlyArrivalTimeCount++
                }
            }

            return earlyArrivalTimeCount
        }

    func printFormattedOutput(array []bool) {
        for _, x := range array {
            if x {
                fmt.Println("YES")
            } else {
                fmt.Println("NO")
            }
        }
    }
