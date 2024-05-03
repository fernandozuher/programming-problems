// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {

    var n, beautifulDifference int
    _, err := fmt.Scan(&n, &beautifulDifference)
    if err != nil {
        return
    }
    array := readIntArray(n)
    fmt.Println(findBeautifulTriplets(array, beautifulDifference))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            _, err := fmt.Scan(&array[i])
            if err != nil {
                return nil
            }
        }
        return array
    }

    func findBeautifulTriplets(array []int, beautifulDifference int) int {
        nBeautifulTriplets := 0

        if len(array) > 2 {
            for i := 0; i < len(array)-2; i++ {
                for j := i + 1; j < len(array)-1; j++ {
                    firstDifference := array[j] - array[i]

                    if firstDifference < beautifulDifference {
                        continue
                    } else if firstDifference > beautifulDifference {
                        break
                    }

                    for k := j + 1; k < len(array); k++ {
                        secondDifference := array[k] - array[j]

                        if secondDifference == beautifulDifference {
                            nBeautifulTriplets++
                        } else if secondDifference > beautifulDifference {
                            break
                        }
                    }
                }
            }
        }
        return nBeautifulTriplets
    }
