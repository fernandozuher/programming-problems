# https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

def main
  word = gets.chomp
  obj = init_queue_and_stack(word)
  check_if_palindrome(obj, word)
end

def init_queue_and_stack(word)
  obj = QueueAndStack.new
  word.each_char do |ch|
    obj.push_character(ch)
    obj.enqueue_character(ch)
  end
  obj
end

class QueueAndStack
  def initialize
    @my_queue = Queue.new
    @my_stack = []
  end

  def enqueue_character(ch)
    @my_queue << ch
  end

  def push_character(ch)
    @my_stack << ch
  end

  def dequeue_character
    @my_queue.pop
  end

  def pop_character
    @my_stack.pop
  end

end

def check_if_palindrome(obj, word)
  is_palindrome = true

  (word.length / 2).times do
    if obj.dequeue_character != obj.pop_character
      is_palindrome = false
      break
    end
  end

  not_word = is_palindrome ? ' ' : ' not '
  puts "The word, #{word}, is#{not_word}a palindrome."
end

main
