// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	isWeird := n&1 == 1 || n >= 6 && n <= 20
	if isWeird {
		fmt.Println("Weird")
	} else {
		fmt.Println("Not Weird")
	}
}
