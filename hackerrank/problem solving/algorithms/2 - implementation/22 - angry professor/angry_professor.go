// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import (
    "fmt"
)


func main() {
    var nTestCases int = readOneInt()
    var nResults []bool = make([]bool, nTestCases)

    for i := range nResults {
        nResults[i] = angryProfessor()
    }

    for i := range nResults {
        if nResults[i] {
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
