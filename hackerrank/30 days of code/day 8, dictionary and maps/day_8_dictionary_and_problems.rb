n = gets.chomp.to_i
phoneBook = Hash.new

for i in 1..n
    name, phone = gets.chomp.split
    phoneBook.store(name, phone)
end

while query = gets
    query = query.chomp
    if phoneBook.key?(query)
        puts "#{query}=#{phoneBook[query]}"
    else    
        puts "Not found"
    end
end
