// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

package main

import "fmt"

func main() {
    house, apple, orange := readInput()
    fmt.Println(countFruitsOnHouse(apple, house))
    fmt.Println(countFruitsOnHouse(orange, house))
}

type House struct {
    start, end int
}

func (h House) contains(position int) bool {
    return h.start <= position && position <= h.end
}

type TreeFruits struct {
    treeLocation   int
    fruitDistances []int
}

func readInput() (House, TreeFruits, TreeFruits) {
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

    apple := TreeFruits{
        appleTreeLocation,
        appleDistances,
    }

    orange := TreeFruits{
        orangeTreeLocation,
        orangeDistances,
    }

    return house, apple, orange
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func countFruitsOnHouse(fruit TreeFruits, house House) int {
    count := 0
    for _, distance := range fruit.fruitDistances {
        position := fruit.treeLocation + distance
        if house.contains(position) {
            count++
        }
    }
    return count
}
