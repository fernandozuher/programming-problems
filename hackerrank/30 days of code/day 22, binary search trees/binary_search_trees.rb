# https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

def main
    my_tree = Solution.new
    root = nil
    T = gets.to_i

    for i in 1..T
        data = gets.to_i
        root = my_tree.insert(root, data)
    end

    height = my_tree.get_height(root)
    print height
end

    class Solution
        @@current_height = 0
        @@max_height = 0

        def insert(root, data)
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
    # Immutable Hacker_rank code above

        def get_height(root)
            if root.left || root.right
                @@current_height += 1

                if root.left
                    get_height(root.left)
                end

                if root.right
                    get_height(root.right)
                end
                
                @@current_height -= 1
                
            elsif @@current_height > @@max_height
                @@max_height = @@current_height
            end

            @@max_height
        end
    end

# Immutable Hacker_rank code below
    class Node
        attr_accessor :left, :right, :data

        def initialize data
          @left = @right = nil
          @data = data
        end
    end

main