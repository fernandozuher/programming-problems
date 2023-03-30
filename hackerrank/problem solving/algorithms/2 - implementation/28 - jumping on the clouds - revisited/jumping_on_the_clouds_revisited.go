// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var sizeArray int = ReadANumber()
    var jumpLength int = ReadANumber()
    var array []int = ReadAnArray(sizeArray)

    var energy int = JumpingOnClouds(array, jumpLength)
    fmt.Println(energy)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func ReadAnArray(sizeArray int) []int {
        var array []int = make([]int, sizeArray)
        for i := 0; i < sizeArray; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func JumpingOnClouds(array []int, jumpLength int) int {
        var energy int = 100

        for cloudIndex := 0; true; {
            energy -= SpentEnergyAccordingToTypeOfCloud(array[cloudIndex])
            cloudIndex = GenerateNewCloudIndex(cloudIndex, len(array), jumpLength)
            if IsCloudIndexBackToFirstCloud(cloudIndex) {
                break
            }
        }

        return energy
    }

        func SpentEnergyAccordingToTypeOfCloud(cloudType int) int {
            if cloudType == 0 {
                return 1
            } else {
                return 3
            }
        }

        func GenerateNewCloudIndex(cloudIndex int, sizeArray int, jumpLength int) int {
            return (cloudIndex + jumpLength) % sizeArray
        }

        func IsCloudIndexBackToFirstCloud(cloudIndex int) bool {
            return cloudIndex == 0
        }
