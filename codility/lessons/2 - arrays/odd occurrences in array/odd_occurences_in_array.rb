# Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

def solution(a)
    a = a.sort
    unpairedElement = a.first
    isElementPaired = false

    for i in 1..a.size
        if a[i] == unpairedElement
            isElementPaired = !isElementPaired
        elsif isElementPaired
            isElementPaired = false
            unpairedElement = a[i]
        else
            break
        end
    end

   unpairedElement
end
