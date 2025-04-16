# https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

def main
  head = read_list
  remove_consecutive_duplicates(head)
  display(head)
end

def read_list
  n = gets.to_i rescue 0
  head = nil
  tail = nil

  n.times do
    new_node = Node.new(gets.to_i)
    if head.nil?
      head = tail = new_node
    else
      tail.next = new_node
      tail = new_node
    end
  end
  head
end

Node = Struct.new(:data, :next)

def remove_consecutive_duplicates(head)
  node = head
  while node&.next
    if node.data == node.next.data
      node.next = node.next.next
    else
      node = node.next
    end
  end
end

def display(head)
  node = head
  while node
    print node.data, ' '
    node = node.next
  end
end

main
