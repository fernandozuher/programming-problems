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
        if grade < minGrade || isZeroRemainder(grade) {
            roundedGrades[i] = grade
        } else {
            quotient := grade / 5
            nextMultiple5 := (quotient + 1) * 5
            difference := nextMultiple5 - grade

            if difference < 3 {
                roundedGrades[i] = nextMultiple5
            } else {
                roundedGrades[i] = grade
            }
        }
    }

    return roundedGrades
}

func isZeroRemainder(grade int) bool {
    return grade%5 == 0
}

func printNumbers(numbers []int) {
    for _, x := range numbers {
        fmt.Println(x)
    }
}
