// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    grades := readNumbers(n)
    roundedGrades := gradeStudents(grades)
    printNumbers(roundedGrades)
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func gradeStudents(grades []int) []int {
    roundedGrades := make([]int, len(grades))
    const minGrade = 38

    for i, grade := range grades {
        if grade < minGrade {
            roundedGrades[i] = grade
        } else {
            nextMultiple5 := (grade/5 + 1) * 5
            if nextMultiple5-grade < 3 {
                roundedGrades[i] = nextMultiple5
            } else {
                roundedGrades[i] = grade
            }
        }
    }

    return roundedGrades
}

func printNumbers(numbers []int) {
    for _, x := range numbers {
        fmt.Println(x)
    }
}
