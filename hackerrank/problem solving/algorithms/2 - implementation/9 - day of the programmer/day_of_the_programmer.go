// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

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

	year := readLineAsIntArray(scanner)

	result := dayOfProgrammer(year[0])
	fmt.Print(result)
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

    func dayOfProgrammer(year int) string {
        var date string

        if year != 1918 {
            var isLeap bool
            
            if year > 1918 {
            	isLeap = isLeapGregorianYear(year)
        	} else {
				isLeap = isLeapJulianYear(year)
        	}
        
        	if isLeap {
        		date = "12.09."
        	} else {
        		date = "13.09."
        	}
        	
        } else {
            date = "26.09."
        }

        date += strconv.Itoa(year)
        
        return date
    }

        func isLeapGregorianYear(year int) bool {
            return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
        }

        func isLeapJulianYear(year int) bool {
            return year % 4 == 0
        }