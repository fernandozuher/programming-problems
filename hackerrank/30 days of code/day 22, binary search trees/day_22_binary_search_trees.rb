class Node
    attr_accessor :left,:right,:data
  def initialize data
      @left=@right=nil
      @data=data
    end
end
class Solution
    def insert (root,data)
        if root==nil
            return Node.new(data)
        else
            if data<=root.data
                cur=self.insert(root.left,data)
                root.left=cur
            else
                cur=self.insert(root.right,data)
                root.right=cur
            end
        end
        return root
    end

    # Immutable HackerRank code above

    @@currentHeight = 0
    @@maxHeight = 0

    def getHeight(root)
        if root.left || root.right
            @@currentHeight += 1

            if root.left
                getHeight(root.left)
            end
            if root.right
                getHeight(root.right)
            end
            
            @@currentHeight -= 1
            
        elsif @@currentHeight > @@maxHeight
            @@maxHeight = @@currentHeight
        end

        return @@maxHeight
    end
end

# Immutable HackerRank code below

myTree=Solution.new
root=nil
T=gets.to_i
for i in 1..T
    data=gets.to_i
    root=myTree.insert(root,data)
end
height=myTree.getHeight(root)
print height