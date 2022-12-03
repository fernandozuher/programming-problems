#!/bin/ruby

def bubbleSort(a)

    numberOfSwaps = 0

    a.each do
        for j in 0..a.length()-2

            if a[j] > a[j + 1]
                a[j], a[j + 1] = a[j + 1], a[j]
                numberOfSwaps += 1
            end
            
            if not numberOfSwaps
                break
            end
        end
    end
    return numberOfSwaps
end

gets

list = gets.rstrip.split.map(&:to_i)

puts "Array is sorted in #{bubbleSort(list)} swaps."
puts "First Element: #{list.first}"
puts "Last Element: #{list.last}"
