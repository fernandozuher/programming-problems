package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    
    scanner.Scan()
    n, _ := strconv.ParseInt(scanner.Text(), 10, 64)

    phoneBook := make(map[string]string)

    for i := int64(0); i < n && scanner.Scan(); i++ {
        line := strings.Split(scanner.Text(), " ")
        phoneBook[line[0]] = line[1]
    }

    for scanner.Scan() {
        query := scanner.Text()
        value, hasKey := phoneBook[query]
        if hasKey {
            fmt.Printf("%s=%s\n", query, value)
        } else {
            fmt.Println("Not found")
        }
    }
}
