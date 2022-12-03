package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

func isZeroRemainder(grade int32) bool {
    return grade % 5 == 0
}

func gradingStudents(grades []int32) []int32 {
    n := len(grades)
    newGrades := make([]int32, n)

    for i, minGrade := 0, int32(38); i < n; i++ {

        if grades[i] < minGrade || isZeroRemainder(grades[i]) {
            newGrades[i] = grades[i]
        } else {
            var quocient int32 = grades[i] / 5
            nextMultiple5 := (quocient + 1) * 5
            difference := nextMultiple5 - grades[i]
            
            var result int32
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

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    gradesCount, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    var grades []int32

    for i := 0; i < int(gradesCount); i++ {
        gradesItemTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
        checkError(err)
        gradesItem := int32(gradesItemTemp)
        grades = append(grades, gradesItem)
    }

    result := gradingStudents(grades)

    for i, resultItem := range result {
        fmt.Fprintf(writer, "%d", resultItem)

        if i != len(result) - 1 {
            fmt.Fprintf(writer, "\n")
        }
    }

    fmt.Fprintf(writer, "\n")

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
