# Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

def solution array
    minimumDifferenceBetweenParts = findMinimumDifferenceBetweenTwoPartsArray array
end

    def findMinimumDifferenceBetweenTwoPartsArray array
        firstPart = array.first
        secondPart = array.sum - firstPart
        minimumDifferenceBetweenParts = (firstPart - secondPart).abs

        for i in 1..(array.size - 2)
            firstPart += array[i]
            secondPart -= array[i]
            currentMinimum = (firstPart - secondPart).abs

            if minimumDifferenceBetweenParts > currentMinimum
                minimumDifferenceBetweenParts = currentMinimum
            end
        end

        minimumDifferenceBetweenParts
    end
