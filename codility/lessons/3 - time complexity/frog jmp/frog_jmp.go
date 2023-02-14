// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

package solution

import "math"

func Solution(currentPosition int, destination int, jumpDistance int) int {
    numberOfJumps := float64((destination - currentPosition)) / float64(jumpDistance)
    minimumNumberOfJumps := int(math.Ceil(numberOfJumps))
    return minimumNumberOfJumps
}
