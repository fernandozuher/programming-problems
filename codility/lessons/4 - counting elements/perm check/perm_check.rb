# Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

require 'set'

def solution(array)
    numbers = SortedSet.new(array)
    numbers.size == array.size && numbers.to_a.last == array.size ? 1 : 0
end
