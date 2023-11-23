// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

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

    for i, minGrade := 0, 38; i < n; i++ {

        if grades[i] < minGrade || isZeroRemainder(grades[i]) {
            newGrades[i] = grades[i]
        } else {
            var quocient int = grades[i] / 5
            var nextMultiple5 int = (quocient + 1) * 5
            var difference int = nextMultiple5 - grades[i]

            var result int
            if difference < 3 {
                result = nextMultiple5
            } else {
                result = grades[i]
            }

            newGrades[i] = result
        }
    }

    return newGrades
}

func isZeroRemainder(grade int) bool {
    return grade%5 == 0
}

func printArray(array []int) {
    for i := range array {
        fmt.Println(array[i])
    }
}
