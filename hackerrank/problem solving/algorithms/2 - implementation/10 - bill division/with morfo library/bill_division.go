// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
	"morfo/morfomath"
)

type Input struct {
	itemNotEaten  int
	mealCosts     []int
	amountCharged int
}

func main() {
	data := readInput()
	if charged := bonAppetit(data); charged > 0 {
		fmt.Println(charged)
	} else {
		fmt.Println("Bon Appetit")
	}
}

func readInput() Input {
	n := morfoio.Read[int]()
	return Input{
		itemNotEaten:  morfoio.Read[int](),
		mealCosts:     morfoio.ReadN[int](n),
		amountCharged: morfoio.Read[int](),
	}
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
func bonAppetit(data Input) int {
	totalSharedCost := morfomath.Sum(data.mealCosts) - data.mealCosts[data.itemNotEaten]
	totalSharedCost /= 2
	return data.amountCharged - totalSharedCost
}
