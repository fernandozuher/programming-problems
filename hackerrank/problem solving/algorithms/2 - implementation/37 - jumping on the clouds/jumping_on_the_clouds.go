// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nClouds int = ReadANumber()
    var cloudArray []int = ReadAnArray(nClouds)
    var minimumNumberOfJumps int = CalculateMinimumNumberOfJumps(cloudArray)
    fmt.Println(minimumNumberOfJumps)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func ReadAnArray(size int) []int {
        var array []int = make([]int, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func CalculateMinimumNumberOfJumps(array []int) int {
        var jumps int = 0

        for i, size := 0, len(array)-1; i < size; {
            i = GetIndexOfNextJump(i, array)
            jumps++
        }

        return jumps
    }

        func GetIndexOfNextJump(index int, array []int) int {
            if IsNextSecondIndexInsideRange(index+2, len(array)) {
                if IsNextSecondCloudCumulus(array[index+2]) {
                    index += 2
                } else {
                    index += 1
                }
            } else {
                index += 1
            }
            return index
        }

            func IsNextSecondIndexInsideRange(index int, size int) bool {
                return index < size
            }

            func IsNextSecondCloudCumulus(typeOfCloud int) bool {
                return typeOfCloud == 0
            }
