package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
    "strconv"
)

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

func timeConversion(time string) string {
    convertedTime := time[0:8]
    hourString := time[0:2]
    periodOfDay := time[8:9]

    if hourString == "12" {
        if periodOfDay == "A" {
            convertedTime = strings.Replace(convertedTime, hourString, "00", 1)
        }
    } else if periodOfDay == "P" {
        hour, _ := strconv.Atoi(hourString)
        hour += 12
        convertedTime = strings.Replace(convertedTime, hourString, strconv.Itoa(hour), 1)
    }
    return convertedTime
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    s := readLine(reader)

    result := timeConversion(s)

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
