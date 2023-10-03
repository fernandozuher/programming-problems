# https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

s = gets.chomp

def convert_to_int(n)
    puts Integer(n)
    rescue
        puts "Bad String"
end

convert_to_int(s)
