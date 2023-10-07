# https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

def main
    my_list = Solution.new
    head = nil
    n_tests = gets.to_i
    
    for _ in 1..n_tests
        data = gets.to_i
        head = my_list.insert(head, data)
    end
    
    head = my_list.remove_duplicates(head)
    my_list.display(head)
end

    class Solution
        def insert(head, value)
            p = Node.new(value)
            
            if head == nil
                head = p
            elsif head.next == nil
                head.next = p
            else
                current = head

                while current.next != nil
                    current = current.next
                end 

                current.next = p
            end

          head   
       end

       def remove_duplicates(head)
            original = head
            while head.next
                head.data == head.next.data ? (head.next = head.next.next) : (head = head.next)
            end
            original
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
