// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

package solution

func Solution(nCounters int, array []int) []int {
    foundMaxCounter := false
    max, currentMax := 0, 0
    counters := map[int]int{}

    for _, element := range array {
        if element <= nCounters {
            if foundMaxCounter == true {
                setDefaultZeroValues(&counters, &foundMaxCounter, &currentMax)
            }

            if counters[element]++; counters[element] > currentMax {
                currentMax++
            }
        } else if foundMaxCounter == false {
            max += currentMax
            foundMaxCounter = true
        }
    }

    return compouseResult(foundMaxCounter, max, nCounters, counters)
}

    func setDefaultZeroValues(counters *map[int]int, foundMaxCounter *bool, currentMax *int) {
        *counters = map[int]int{}
        *foundMaxCounter = false
        *currentMax = 0
    }

    func compouseResult(foundMaxCounter bool, max int, nCounters int, counters map[int]int) []int {
        initialValue := 0
        if foundMaxCounter == true || max > 0 {
            initialValue = max
        }

        result := make([]int, nCounters+1)
        setValueToSlice(result, initialValue)

        if !foundMaxCounter {
            for counter, value := range counters {
                result[counter] += value
            }
        }

        return result[1:]
    }

        func setValueToSlice(slice []int, value int) {
            for i := 0; i < len(slice); i++ {
                slice[i] = value
            }
        }
