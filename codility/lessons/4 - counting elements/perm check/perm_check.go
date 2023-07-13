// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

package solution

import "sort"

func Solution(array []int) int {
    sort.Ints(array)
    var i int
    for i = 0; i < len(array) && array[i] == i+1; i++ {
    }

    if i == len(array) {
        return 1
    }
    return 0
}
