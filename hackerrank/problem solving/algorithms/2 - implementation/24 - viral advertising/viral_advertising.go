package main

import "fmt"


func main() {
	var days int
	fmt.Scan(&days)

	var cumulative_likes int = viral_advertising(days)
	fmt.Println(cumulative_likes)
}

	func viral_advertising(days int) int {
		var shared, liked, cumulative int = 5, 0, 0

		for i := 0; i < days; i++ {
			liked = shared / 2
			cumulative += liked
			shared = liked * 3
		}

		return cumulative
	}
