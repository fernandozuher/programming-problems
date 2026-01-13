// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import "fmt"

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

func main() {
    house, appleTree, orangeTree := readInput()
    fmt.Println(countFruitsOnHouse(appleTree, house))
    fmt.Println(countFruitsOnHouse(orangeTree, house))
}

func readInput() (House, FruitTree, FruitTree) {
    var houseStart int
    var houseEnd int
    var appleTreeLocation int
    var orangeTreeLocation int
    var nApples int
    var nOranges int

    _, _ = fmt.Scan(&houseStart, &houseEnd)
    _, _ = fmt.Scan(&appleTreeLocation, &orangeTreeLocation)
    _, _ = fmt.Scan(&nApples, &nOranges)
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
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
func countFruitsOnHouse(fruitTree FruitTree, house House) int {
    count := 0
    for _, distance := range fruitTree.fruitDistances {
        if house.contains(fruitTree.treeLocation + distance) {
            count++
        }
    }
    return count
}
