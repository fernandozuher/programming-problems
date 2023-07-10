// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

package solution

import "math"

func Solution(currentPosition int, destination int, jumpDistance int) int {
    return int(math.Ceil(float64(destination - currentPosition) / float64(jumpDistance)))
}
