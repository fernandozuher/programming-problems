// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

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
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

func kangaroo(x1 int32, v1 int32, x2 int32, v2 int32) string {
    if v2 >= v1 {
        return "NO"
    }

    for ; x1 < x2; x1, x2 = x1+v1, x2+v2 {}

    if x1 == x2 {
        return "YES"
    } else {
        return "NO"
    }
}

func main() {
    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)
    defer stdout.Close()
    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    numbers := readInputAsI32Array()
    x1 := numbers[0]
    v1 := numbers[1]
    x2 := numbers[2]
    v2 := numbers[3]

    result := kangaroo(x1, v1, x2, v2)
    fmt.Fprintf(writer, "%s\n", result)
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

func readInputAsI32Array() []int32 {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)
    inputStringArray := strings.Split(readLine(reader), " ")
    numbers := make([]int32, len(inputStringArray))

    for i, stringNumber := range inputStringArray {
        number, err := strconv.Atoi(stringNumber)
        if err != nil {
            panic(err)
        }
        numbers[i] = int32(number)
    }
    return numbers
}
