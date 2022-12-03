class Node

    attr_accessor :data, :next

    def initialize data
        @data = data
        @next = nil
    end
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

        return head
    end

    def display(head)

       current = head

       while current 
          print current.data, " "
          current = current.next
       end

   end

end
       
mylist = Solution.new
head = nil
T = gets.to_i

for i in 1..T
    data = gets.to_i
    head = mylist.insert(head, data)
end

mylist.display(head)