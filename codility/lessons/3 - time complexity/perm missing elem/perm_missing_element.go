// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

package solution

import "sort"

func Solution(array []int) int {
    sort.Ints(array)
    var missingElement int = findMissingElement(array)
    return missingElement
}

    func findMissingElement(array []int) int {
        var i int

        for i = 0; i < len(array); i++ {
            if array[i] != i+1 {
                break
            }
        }

        return i + 1
    }
