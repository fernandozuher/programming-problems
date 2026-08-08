// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

package main

import "morfo/morfoio"

func main() {
    n := morfoio.Read[int]()
    grades := morfoio.ReadN[int](n)
    morfoio.Println(gradingStudents(grades))
}

// n: length of grades
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
