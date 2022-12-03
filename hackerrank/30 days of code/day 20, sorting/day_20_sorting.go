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
    
    aTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    var list []int32

    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        aItem := int32(aItemTemp)
        list = append(list, aItem)
    }

    fmt.Printf("Array is sorted in %d swaps.", bubble_sort(list))
    fmt.Printf("\nFirst Element: %d", list[0])
    fmt.Printf("\nLast Element: %d", list[len(list) - 1])
}

func bubble_sort(a []int32) int {

    number_of_swaps := 0
    
    for range a {
        for j, N := 0, len(a) - 1; j < N; j++ {
            if a[j] > a[j + 1] {
                a[j], a[j + 1] = a[j + 1], a[j]
                number_of_swaps++
            }
        }

        if number_of_swaps == 0 {
            break
        }
    }
    return number_of_swaps
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
