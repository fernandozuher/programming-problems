// https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

package solution

func Solution(array []int) int {
    passingCarsPairs := 0

    for i, east, west, passingCarsLimit := 0, 0, 0, 1000000000; i < len(array); i++ {
        if west = array[i]; west == 1 {
            if passingCarsPairs += east; passingCarsPairs > passingCarsLimit {
                return -1
            }
        } else {
            east++
        }
    }

    return passingCarsPairs
}
