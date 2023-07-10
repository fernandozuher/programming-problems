# Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

def solution(a)
    a.sort!
    unpaired_element = a.first
    is_element_paired = false

    for i in 1..a.size
        if a[i] == unpaired_element
            is_element_paired = !is_element_paired
        elsif is_element_paired
            is_element_paired = false
            unpaired_element = a[i]
        else
            break
        end
    end

   unpaired_element
end
