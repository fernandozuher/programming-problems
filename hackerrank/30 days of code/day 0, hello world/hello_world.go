// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimRight(input, "\n")
    fmt.Println("Hello, World.")
    fmt.Println(input)
}
