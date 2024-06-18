// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    printArray(gradingStudents(array))
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func gradingStudents(grades []int) []int {
    n := len(grades)
    newGrades := make([]int, n)
    minGrade := 38

    for i := range n {
        if grades[i] < minGrade || isZeroRemainder(grades[i]) {
            newGrades[i] = grades[i]
        } else {
            var quotient int = grades[i] / 5
            var nextMultiple5 int = (quotient + 1) * 5
            var difference int = nextMultiple5 - grades[i]

            if difference < 3 {
                newGrades[i] = nextMultiple5
            } else {
                newGrades[i] = grades[i]
            }
        }
    }

    return newGrades
}

func isZeroRemainder(grade int) bool {
    return grade%5 == 0
}

func printArray(array []int) {
    for _, x := range array {
        fmt.Println(x)
    }
}
