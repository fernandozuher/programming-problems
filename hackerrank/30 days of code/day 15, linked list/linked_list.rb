# https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

def main
  n = gets.to_i
  list = initialize_list(n)
  list.display
end

def initialize_list(n)
  list = SinglyLinkedList.new
  n.times do
    list.insert(gets.to_i)
  end
  list
end

class SinglyLinkedList

  Node = Struct.new(:data, :next)

  def initialize
    @head = nil
  end

  def insert(data)
    tail = tail_node
    if tail
      tail.next = Node.new(data)
    else
      @head = Node.new(data)
    end
  end

  private def tail_node
    tail = @head
    while tail&.next
      tail = tail.next
    end
    tail
  end

  def display
    node = @head
    while node
      print "#{node.data} "
      node = node.next
    end
  end
end

main
