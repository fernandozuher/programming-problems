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
    var startingSam, endingSam int
    fmt.Scan(&startingSam, &endingSam)

    var appleTreeLocation, orangeTreeLocation int
    fmt.Scan(&appleTreeLocation, &orangeTreeLocation)

    var nApples, nOranges int
    fmt.Scan(&nApples, &nOranges)

    var applesDistanceFromTree []int = readIntArray(nApples)
    var orangesDistanceFromTree []int = readIntArray(nOranges)

    return AppleAndOrange{startingSam, endingSam,
        appleTreeLocation, orangeTreeLocation,
        nApples, nOranges,
        applesDistanceFromTree, orangesDistanceFromTree}
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scanf("%d", &array[i])
    }
    return array
}

func countApplesAndOranges(input AppleAndOrange) {
    var applesOnHouse int = countFruitsOnHouse(input, "apple")
    var orangesOnHouse int = countFruitsOnHouse(input, "orange")
    fmt.Printf("%d\n%d", applesOnHouse, orangesOnHouse)
}

func countFruitsOnHouse(input AppleAndOrange, fruit string) int {
    var filteredInput [][]int = filterInput(input, fruit)
    var treeLocation int = filteredInput[0][0]
    var fruits []int = filteredInput[1]

    var fruitsOnHouse int = 0
    for _, partialLocation := range fruits {
        location := treeLocation + partialLocation
        if location >= input.startingSam && location <= input.endingSam {
            fruitsOnHouse += 1
        }
    }

    return fruitsOnHouse
}

func filterInput(input AppleAndOrange, fruit string) [][]int {
    const data int = 2
    var filteredInput [][]int = make([][]int, data)
    filteredInput[0] = make([]int, 1)

    if fruit == "apple" {
        filteredInput[0][0] = input.appleTreeLocation
        filteredInput[1] = input.applesDistanceFromTree
    } else {
        filteredInput[0][0] = input.orangeTreeLocation
        filteredInput[1] = input.orangesDistanceFromTree
    }

    return filteredInput
}
