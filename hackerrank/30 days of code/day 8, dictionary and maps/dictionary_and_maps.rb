# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

def main
  n = gets.to_i
  phone_book = init_phone_book(n)
  query_names(phone_book)
end

def init_phone_book(n)
  phone_book = Hash.new
  n.times {
    name, phone = gets.split
    phone_book.store(name, phone)
  }
  phone_book
end

def query_names(phone_book)
  while (name = gets&.chomp)
    if (value = phone_book[name])
      puts "#{name}=#{value}"
    else
      puts 'Not found'
    end
  end
end

main
