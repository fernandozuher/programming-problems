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
    def levelOrder(root)

        if not root
            return
        end
        
        print root.data, " "

        myQueue = Queue.new
        myQueue << root

        while not myQueue.empty?

            first = myQueue.pop
            if first.left
                myQueue << first.left
                print first.left.data, " "
            end
            if first.right
                myQueue << first.right
                print first.right.data, " "
            end
        end
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
myTree.levelOrder(root)
