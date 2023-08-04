# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

def main
    n = gets.to_i
    phone_book = Hash.new

    for i in 0...n
        name, phone = gets.split
        phone_book.store(name, phone)
    end

    while name = gets&.chomp
        if value = phone_book[name]
            puts "#{name}=#{value}"
        else    
            puts "Not found"
        end
    end
end

main
