# https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

def main
  root = read_tree
  level_order(root)
end

def read_tree
  root = nil
  n = gets.to_i rescue 0
  n.times {
    data = gets.to_i
    root = insert_node(root, data)
  }
  root
end

def insert_node(root, data)
  if root.nil?
    return Node.new(data, nil, nil)
  end
  if data <= root.data
    root.left = insert_node(root.left, data)
  else
    root.right = insert_node(root.right, data)
  end
  root
end

Node = Struct.new(:data, :left, :right)

def level_order(root)
  unless root
    return
  end

  my_queue = Queue.new
  my_queue << root
  until my_queue.empty?
    current = my_queue.pop
    print current.data, ' '
    if current.left
      my_queue << current.left
    end
    if current.right
      my_queue << current.right
    end
  end
end

main
