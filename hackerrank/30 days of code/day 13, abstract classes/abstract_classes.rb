# https://www.hackerrank.com/challenges/30-abstract-classes/problem?isFullScreen=true

def main:
    title = gets.rstrip
    author = gets.rstrip
    price = gets.rstrip

    novel = MyBook.new(title, author, price)
    novel.display
end

    # This is a **simulation** of an abstract class provided at user request. #
    class Book
        attr_accessor :title
        attr_accessor :author
        
        def initialize(title, author)
            raise 'You cannot instantiate an abstract class.'
        end
        
        def display
            raise 'You must override this method in your implementing class.'
        end
    end

        class MyBook < Book
            attr_accessor :price

            def initialize(title, author, price)
                @title = title
                @author = author
                @price = price
            end

            def display
                puts "Title: #{title} \nAuthor: #{author} \nPrice: #{price}"
            end
        end

main
