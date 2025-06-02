// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import "fmt"

func main() {
    house, appleTree, orangeTree := readInput()
    fmt.Println(countFruitsOnHouse(appleTree, house))
    fmt.Println(countFruitsOnHouse(orangeTree, house))
}

type House struct {
    start, end int
}

func (h House) contains(position int) bool {
    return h.start <= position && position <= h.end
}

type FruitTree struct {
    treeLocation   int
    fruitDistances []int
}

func readInput() (House, FruitTree, FruitTree) {
    var houseStart int
    var houseEnd int
    var appleTreeLocation int
    var orangeTreeLocation int
    var nApples int
    var nOranges int

    fmt.Scan(&houseStart)
    fmt.Scan(&houseEnd)
    fmt.Scan(&appleTreeLocation)
    fmt.Scan(&orangeTreeLocation)
    fmt.Scan(&nApples)
    fmt.Scan(&nOranges)
    appleDistances := readNumbers(nApples)
    orangeDistances := readNumbers(nOranges)

    house := House{houseStart, houseEnd}

    appleTree := FruitTree{
        appleTreeLocation,
        appleDistances,
    }

    orangeTree := FruitTree{
        orangeTreeLocation,
        orangeDistances,
    }

    return house, appleTree, orangeTree
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func countFruitsOnHouse(fruitTree FruitTree, house House) int {
    count := 0
    for _, distance := range fruitTree.fruitDistances {
        position := fruitTree.treeLocation + distance
        if house.contains(position) {
            count++
        }
    }
    return count
}
