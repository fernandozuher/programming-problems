// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

package solution

import "sort"

func Solution(A []int) int {
    sort.Ints(A)
    unpairedElement := A[0]
    isElementPaired := false

    for i, N := 1, len(A); i < N; i++ {
        if A[i] == unpairedElement {
            isElementPaired = !isElementPaired
        } else if isElementPaired {
            isElementPaired = false
            unpairedElement = A[i]
        } else {
            break
        }
    }

    return unpairedElement
}
