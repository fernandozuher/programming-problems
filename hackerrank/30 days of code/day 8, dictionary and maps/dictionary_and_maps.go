// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

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
    n, _ := strconv.Atoi(scanner.Text())

    phoneBook := make(map[string]string)

    for i := 0; i < n && scanner.Scan(); i++ {
        line := strings.Split(scanner.Text(), " ")
        phoneBook[line[0]] = line[1]
    }

    for scanner.Scan() {
        name := scanner.Text()
        value, hashKey := phoneBook[name]

        if hashKey {
            fmt.Printf("%s=%s\n", name, value)
        } else {
            fmt.Println("Not found")
        }
    }
}
