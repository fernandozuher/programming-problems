gets.chomp.to_i.times do
    number = gets.chomp.to_i

    if number == 1
        puts "Not prime"
        next
    end

    i, limit = 2, Math.sqrt(number)
    while i <= limit
        if number.modulo(i).zero?
            puts "Not prime"
            break
        end
        i += 1
    end

    if i > limit
        puts "Prime"
    end
end
