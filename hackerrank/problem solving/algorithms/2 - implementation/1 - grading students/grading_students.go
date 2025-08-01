// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    for _, x := range gradeStudents(readNumbers(n)) {
        fmt.Println(x)
    }
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func gradeStudents(grades []int) []int {
    roundedGrades := make([]int, len(grades))
    for i, grade := range grades {
        roundedGrades[i] = roundGrade(grade)
    }
    return roundedGrades
}

func roundGrade(grade int) int {
    const minGrade = 38
    if grade < minGrade {
        return grade
    }
    remainder := grade % 5
    if remainder >= 3 {
        grade += 5 - remainder
    }
    return grade
}
