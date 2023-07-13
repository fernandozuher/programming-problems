// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

using System.Collections.Generic;
using System.Linq;

class Solution {
    public int solution(int[] array) {
        SortedSet<int> numbers = new SortedSet<int>(array);
        return numbers.Count == array.Length && numbers.ElementAt(numbers.Count - 1) == array.Length ? 1 : 0;
    }
}
