// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

package solution

func Solution(nCounters int, array []int) []int {
    foundMaxCounter := false
    max := 0
    counters := make([]int, nCounters+1)

    for i, currentMax := 0, 0; i < len(array); i++ {
        if array[i] <= nCounters {
            if foundMaxCounter == true {
                // This is faster than just create another default slice
                set_default_value_to_slice(counters, 0)
                foundMaxCounter = false
                currentMax = 0
            }

            counters[array[i]]++
            if counters[array[i]] > currentMax {
                currentMax++
            }
        } else if foundMaxCounter == false {
            max += currentMax
            foundMaxCounter = true
        }
    }

    if foundMaxCounter == true {
        set_default_value_to_slice(counters, max)
    } else if max > 0 {
        add_value_to_slice(counters, max)
    }

    return counters[1:]
}

    func set_default_value_to_slice(slice []int, value int) {
        for i := 0; i < len(slice); i++ {
            slice[i] = value
        }
    }

    func add_value_to_slice(slice []int, value int) {
        for i := 0; i < len(slice); i++ {
            slice[i] += value
        }
    }
