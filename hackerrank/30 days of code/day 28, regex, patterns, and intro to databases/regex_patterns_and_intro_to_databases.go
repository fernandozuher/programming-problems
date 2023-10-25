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
    var names []string = findNamesWithGmailDomainsEmailsFromStdin(n)
    sortInPlaceAndPrintNames(names)
}

    func findNamesWithGmailDomainsEmailsFromStdin(n int) []string {
        var names []string

        for i := 0; i < n; i++ {
            var name, emailId string
            fmt.Scan(&name, &emailId)
            if strings.Contains(emailId, "@gmail.com") {
                names = append(names, name)
            }
        }

        return names
    }

    func sortInPlaceAndPrintNames(names []string) {
        sort.Strings(names)
        for _, x := range names {
            fmt.Println(x)
        }
    }
