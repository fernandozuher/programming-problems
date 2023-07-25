// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    line, _ := reader.ReadString('\n')
    fmt.Println("Hello, World.")
    fmt.Println(line)
}
