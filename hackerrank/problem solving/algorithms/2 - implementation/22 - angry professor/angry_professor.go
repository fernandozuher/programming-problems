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
        studentsArrivalTime := readNumbers(nStudentsArrivalTime)
        cancelledClasses[i] = angryProfessor(studentsArrivalTime, cancellationThreshold)
    }

    printFormattedOutput(cancelledClasses)
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func angryProfessor(studentsArrivalTime []int, cancellationThreshold int) bool {
    return countEarlyArrivalTime(studentsArrivalTime) < cancellationThreshold
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

func printFormattedOutput(data []bool) {
    for _, x := range data {
        if x {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}
