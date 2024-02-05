# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main
    n = gets.to_i
    prisoners_chair_number_to_warn = Array.new(n)

    n.times do |i|
        prisoners, sweets, chair_number_to_begin = read_int_array
        prisoners_chair_number_to_warn[i] = save_the_prisoner(prisoners, sweets, chair_number_to_begin)
    end

    puts prisoners_chair_number_to_warn
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    def save_the_prisoner(prisoners, sweets, chair_number_to_begin)
        prisoner_chair_number_to_warn = chair_number_to_begin + (sweets - 1)
        x = prisoner_chair_number_to_warn

        if x > prisoners
            x %= prisoners
            if x == 0
                x = prisoners
            end
        end

        x
    end

main
