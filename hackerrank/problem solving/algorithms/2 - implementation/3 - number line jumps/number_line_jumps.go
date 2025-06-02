// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const N = 4
    positionsAndVelocities := readNumbers(N)
    if kangaroo(positionsAndVelocities) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func kangaroo(positionsAndVelocities []int) bool {
    x1 := positionsAndVelocities[0]
    v1 := positionsAndVelocities[1]
    x2 := positionsAndVelocities[2]
    v2 := positionsAndVelocities[3]

    if v1 == v2 {
        return x1 == x2
    }

    distanceDiff := x2 - x1
    velocityDiff := v1 - v2
    return distanceDiff*velocityDiff >= 0 && distanceDiff%velocityDiff == 0
}
