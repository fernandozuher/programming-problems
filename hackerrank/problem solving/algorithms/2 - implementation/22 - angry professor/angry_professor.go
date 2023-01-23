// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import (
    "fmt"
)


func main() {
    var nTestCases int = readOneInt()
    var results []bool = make([]bool, nTestCases)

    for i := range results {
        results[i] = angryProfessor()
    }

    for i := range results {
        if results[i] {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

    func readOneInt() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func angryProfessor() bool {
        var nStudentsArrivalTime int = readOneInt()
        var cancellationThreshold int = readOneInt()
        var cancelledClass bool = countEarlyArrivalTime(nStudentsArrivalTime) < cancellationThreshold
        return cancelledClass
    }

        func countEarlyArrivalTime(nStudentsArrivalTime int) int {
            earlyArrivalTimeCount := 0

            for i, studentArrivalTime := 0, 0; i < nStudentsArrivalTime; i++ {
                studentArrivalTime = readOneInt()

                if studentArrivalTime <= 0 {
                    earlyArrivalTimeCount++
                }
            }

            return earlyArrivalTimeCount
        }
