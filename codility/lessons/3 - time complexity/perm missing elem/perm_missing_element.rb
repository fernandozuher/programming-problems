# Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

def solution(array)
    array.sort!
    find_missing_element(array)
end

    def find_missing_element(array)
        index = -1

        array.each_with_index do |element, i|
            if element != i + 1
                index = i + 1
                break
            end
        end

        index == -1 ? array.size + 1 : index
    end
