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
    phoneBook := initPhoneBook(n, scanner)
    queryNames(phoneBook, scanner)
}

func initPhoneBook(n int, scanner *bufio.Scanner) map[string]string {
    phoneBook := make(map[string]string)
    for i := 0; i < n && scanner.Scan(); i++ {
        line := strings.Split(scanner.Text(), " ")
        phoneBook[line[0]] = line[1]
    }
    return phoneBook
}

func queryNames(phoneBook map[string]string, scanner *bufio.Scanner) {
    for scanner.Scan() {
        name := scanner.Text()
        if value, hashKey := phoneBook[name]; hashKey {
            fmt.Printf("%s=%s\n", name, value)
        } else {
            fmt.Println("Not found")
        }
    }
}
