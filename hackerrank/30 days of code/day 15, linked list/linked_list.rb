# https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

def main
    my_list = Solution.new
    head = nil
    T = gets.to_i

    T.times do
        data = gets.to_i
        head = my_list.insert(head, data)
    end

    my_list.display(head)
end

    class Solution

        def insert(head, value)
            if head
                start = head
                while start.next
                    start = start.next
                end
                start.next = Node.new(value)
            else
                start = Node.new(value)
                head = start
            end

            head
        end

        def display(head)
           current = head
           while current 
              print current.data, ' '
              current = current.next
           end
       end
    end

        class Node
            attr_accessor :data, :next

            def initialize(data)
                @data = data
                @next = nil
            end
        end

main
