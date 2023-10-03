# https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

def main
    word = gets
    obj = QueuesAndStacks.new
    
    word.each_char do |ch|
        obj.push_character(ch)
        obj.enqueue_character(ch)
    end

    check_if_word_is_palindrome(obj, word)
end

    class QueuesAndStacks
        def initialize()
            @my_stack = []
            @my_queue = Queue.new
        end

        def push_character(ch)
            @my_stack << ch
        end

        def enqueue_character(ch)
            @my_queue << ch
        end

        def pop_character
            @my_stack.pop
        end

        def dequeue_character
            @my_queue.pop
        end
    end

    def check_if_word_is_palindrome(obj, word)
        is_palindrome = true

        (input.length / 2).times do
            if solution.pop_character != solution.dequeue_character
                is_palindrome = false
                break
            end
        end

        not_word = is_palindrome ? ' ' : ' not '
        puts "The word, #{input}, is#{not_word}a palindrome."
    end

main
