// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

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
    houseStart := morfoio.Read[int]()
    houseEnd := morfoio.Read[int]()
    appleTreeLocation := morfoio.Read[int]()
    orangeTreeLocation := morfoio.Read[int]()
    nApples := morfoio.Read[int]()
    nOranges := morfoio.Read[int]()
    appleDistances := morfoio.ReadN[int](nApples)
    orangeDistances := morfoio.ReadN[int](nOranges)

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

// n: length of fruitTree.fruitDistances
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
