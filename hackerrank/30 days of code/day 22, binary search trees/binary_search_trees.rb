# https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

def main
  root = read_tree
  puts get_height(root)
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
    return Node.new(data: data, left: nil, right: nil)
  end
  if data <= root.data
    root.left = insert_node(root.left, data)
  else
    root.right = insert_node(root.right, data)
  end
  root
end

Node = Struct.new(:data, :left, :right)

def get_height(root)
  if root.nil?
    return -1
  end
  left_height = get_height(root.left)
  right_height = get_height(root.right)
  [left_height, right_height].max + 1
end

main
