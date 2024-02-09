// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, jumpLength int
    fmt.Scan(&n, &jumpLength)
    var array []int = readIntArray(n)
    fmt.Println(jumpingOnClouds(array, jumpLength))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func jumpingOnClouds(clouds []int, jumpLength int) int {
        var energy int = 100

        for cloudIndex := 0; true; {
            energy -= spentEnergyAccordingToTypeOfCloud(clouds[cloudIndex])
            cloudIndex = generateNewCloudIndex(cloudIndex, len(clouds), jumpLength)
            if isCloudIndexBackToFirstCloud(cloudIndex) {
                break
            }
        }

        return energy
    }

        func spentEnergyAccordingToTypeOfCloud(cloudType int) int {
            if cloudType == 0 {
                return 1
            } else {
                return 3
            }
        }

        func generateNewCloudIndex(cloudIndex int, n int, jumpLength int) int {
            return (cloudIndex + jumpLength) % n
        }

        func isCloudIndexBackToFirstCloud(cloudIndex int) bool {
            return cloudIndex == 0
        }
