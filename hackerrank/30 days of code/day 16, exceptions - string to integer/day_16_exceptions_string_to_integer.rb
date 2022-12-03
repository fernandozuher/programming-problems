#!/bin/ruby

S = gets.chomp

def convert_to_int(n)
    puts Integer(n)
    rescue
        puts "Bad String"
end

convert_to_int(S)
