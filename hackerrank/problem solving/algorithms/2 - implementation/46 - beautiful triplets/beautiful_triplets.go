// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var size uint32 = readANumber()
    var beautifulDifference uint32 = readANumber()
    var array []uint32 = readAnArray(size)

    var nBeautifulTriplets uint32 = findBeautifulTriplets(array, beautifulDifference)
    fmt.Println(nBeautifulTriplets)
}

    func readANumber() uint32 {
        var number uint32
        fmt.Scan(&number)
        return number
    }

    func readAnArray(size uint32) []uint32 {
        var array []uint32 = make([]uint32, size)
        for i := uint32(0); i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findBeautifulTriplets(array []uint32, beautifulDifference uint32) uint32 {
        var nBeautifulTriplets uint32 = 0

        if len(array) > 2 {
            for i := 0; i < len(array)-2; i++ {
                for j := i + 1; j < len(array)-1; j++ {
                    var firstDifference uint32 = array[j] - array[i]

                    if firstDifference < beautifulDifference {
                        continue
                    } else if firstDifference > beautifulDifference {
                        break
                    }

                    for k := j + 1; k < len(array); k++ {
                        var secondDifference uint32 = array[k] - array[j]

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
