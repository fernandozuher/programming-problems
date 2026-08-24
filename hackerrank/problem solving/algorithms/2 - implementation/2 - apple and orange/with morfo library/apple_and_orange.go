// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
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
	houseStart, houseEnd := morfoio.Read2[int, int]()
	appleTreeLocation, orangeTreeLocation := morfoio.Read2[int, int]()
	nApples, nOranges := morfoio.Read2[int, int]()
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
	return morfocollections.CountFunc(fruitTree.fruitDistances, func(distance int) bool {
		return house.contains(fruitTree.treeLocation + distance)
	})
}
