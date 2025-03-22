# https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

def main
  title = gets.strip
  author = gets.strip
  price = gets.strip
  novel = MyBook.new(title, author, price)
  novel.display
end

# Simulation of an abstract class
class Book
  def initialize(title, author)
    raise 'You cannot instantiate an abstract class.'
  end

  def display
    raise 'You must override this method in your implementing class.'
  end
end

class MyBook < Book
  def initialize(title, author, price)
    @title = title
    @author = author
    @price = price
  end

  def display
    puts "Title: #{@title} \nAuthor: #{@author} \nPrice: #{@price}"
  end
end

main
