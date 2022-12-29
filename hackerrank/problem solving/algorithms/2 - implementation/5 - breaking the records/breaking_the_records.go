// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	readLineAsIntArray(scanner)
	setA := readLineAsIntArray(scanner)

	result := breakingRecords(setA)
	fmt.Print(result[0], result[1])
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
    	var inputLine string

    	if scanner.Scan() {
    		inputLine = scanner.Text()
    	} else {
    		checkError(scanner.Err())
    	}

    	inputStringArray := strings.Split(inputLine, " ")
    	numbers := make([]int, len(inputStringArray))

    	for i, stringNumber := range inputStringArray {
    		number, err := strconv.Atoi(stringNumber)
    		checkError(err)
    		numbers[i] = number
    	}
    	return numbers
    }

        func checkError(err error) {
        	if err != nil {
        		panic(err)
        	}
        }

    func breakingRecords(scores []int) [2]int {
    	least_points, least_points_count := scores[0], 0
    	most_points, most_points_count := scores[0], 0

    	for _, score := range scores {
    		if score > most_points {
    			most_points = score
    			most_points_count++
    		} else if score < least_points {
    			least_points = score
    			least_points_count++
    		}
    	}

    	records := [2]int{most_points_count, least_points_count}
    	return records
    }
