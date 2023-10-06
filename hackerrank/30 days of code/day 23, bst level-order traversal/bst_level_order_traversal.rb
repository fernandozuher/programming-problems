# https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

def main
    my_tree = Tree.new
    root = nil
    n_tests = gets.to_i

    for i in 1..n_tests
        data = gets.to_i
        root = my_tree.insert(root, data)
    end

    my_tree.level_order(root)
end

    class Tree
        def insert (root, data)
            if root == nil
                return Node.new(data)
            else
                if data <= root.data
                    cur = self.insert(root.left, data)
                    root.left = cur
                else
                    cur = self.insert(root.right, data)
                    root.right = cur
                end
            end

            return root
        end

        def level_order(root)
            if not root
                return
            end

            print root.data, ' '
            my_queue = Queue.new
            my_queue << root

            while not my_queue.empty?
                first = my_queue.pop

                if first.left
                    my_queue << first.left
                    print first.left.data, ' '
                end

                if first.right
                    my_queue << first.right
                    print first.right.data, ' '
                end
            end
        end
    end

        class Node
            attr_accessor :left, :right, :data
            def initialize data
                @left=@right=nil
                @data=data
            end
        end

main
