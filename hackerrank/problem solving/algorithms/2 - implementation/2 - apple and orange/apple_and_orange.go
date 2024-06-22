// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var input AppleAndOrange = readInput()
    countApplesAndOranges(input)
}

type AppleAndOrange struct {
    startingSam, endingSam                int
    appleTreeLocation, orangeTreeLocation int
    nApples, nOranges                     int
    applesDistanceFromTree                []int
    orangesDistanceFromTree               []int
}

func readInput() AppleAndOrange {
    var input AppleAndOrange
    fmt.Scan(&input.startingSam, &input.endingSam)
    fmt.Scan(&input.appleTreeLocation, &input.orangeTreeLocation)
    fmt.Scan(&input.nApples, &input.nOranges)
    input.applesDistanceFromTree = readIntArray(input.nApples)
    input.orangesDistanceFromTree = readIntArray(input.nOranges)
    return input
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func countApplesAndOranges(input AppleAndOrange) {
    var applesOnHouse int = countFruitsOnHouse(input, "apple")
    var orangesOnHouse int = countFruitsOnHouse(input, "orange")
    fmt.Printf("%d\n%d", applesOnHouse, orangesOnHouse)
}

func countFruitsOnHouse(input AppleAndOrange, fruit string) int {
    treeLocation, fruits := filterInput(input, fruit)
    fruitsOnHouse := 0

    for _, partialLocation := range fruits {
        location := treeLocation + partialLocation
        if location >= input.startingSam && location <= input.endingSam {
            fruitsOnHouse += 1
        }
    }

    return fruitsOnHouse
}

func filterInput(input AppleAndOrange, fruit string) (int, []int) {
    if fruit == "apple" {
        return input.appleTreeLocation, input.applesDistanceFromTree
    }
    return input.orangeTreeLocation, input.orangesDistanceFromTree
}
