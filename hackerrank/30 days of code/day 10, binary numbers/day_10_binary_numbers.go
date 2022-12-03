package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {

    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int32(nTemp)
    max_ones, ones := 0, 0
        
    for ones = 0; n > 0; n /= 2 {
        if (n % 2 == 1) {
            ones++
        } else {
            if (ones > max_ones) {
                max_ones = ones
            }
            ones = 0
        }
    }

    if ones > max_ones {
        fmt.Print(ones)
    } else {
        fmt.Print(max_ones)
    }
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
