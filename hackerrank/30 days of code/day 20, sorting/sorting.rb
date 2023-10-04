# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

def main
    _ = gets
    list = gets.split.map(&:to_i)

    puts "Array is sorted in #{bubble_sort(list)} swaps."
    puts "First Element: #{list.first}"
    puts "Last Element: #{list.last}"
end

    def bubble_sort(a)
        numberOfSwaps = 0

        for n in (a.size-1).downto(0)
            for i in 0...n
                if a[i] > a[i + 1]
                    a[i], a[i + 1] = a[i + 1], a[i]
                    numberOfSwaps += 1
                end
                
                if not numberOfSwaps
                    break
                end
            end
        end

        return numberOfSwaps
    end

main
