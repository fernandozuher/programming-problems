// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    grades := readNumbers(n)
    for _, x := range gradingStudents(grades) {
        fmt.Println(x)
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
func gradingStudents(grades []int) []int {
    const minGrade = 38

    for i, grade := range grades {
        if grade >= minGrade {
            if nextMultiple5 := (grade/5 + 1) * 5; nextMultiple5-grade < 3 {
                grades[i] = nextMultiple5
            }
        }
    }

    return grades
}