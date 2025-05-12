// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
    "strings"
)

func main() {
    var n int
    fmt.Scan(&n)
    names := collectGmailUsers(n)
    sort.Strings(names)
    fmt.Println(strings.Join(names, "\n"))
}

func collectGmailUsers(n int) []string {
    var names []string

    for range n {
        var name, email string
        fmt.Scan(&name, &email)
        if strings.HasSuffix(email, "@gmail.com") {
            names = append(names, name)
        }
    }

    return names
}
