class Node:
    def __init__(self, data):
        self.right = self.left = None
        self.data = data


class Solution:
    def insert(self, root, data):
        if root == None:
            return Node(data)
        else:
            if data <= root.data:
                cur = self.insert(root.left, data)
                root.left = cur
            else:
                cur = self.insert(root.right, data)
                root.right = cur
        return root

    # Immutable HackerRank code above

    currentHeight = 0
    maxHeight = 0

    def getHeight(self, root):

        if root.left or root.right:

            Solution.currentHeight += 1

            if root.left:
                self.getHeight(root.left)
            if root.right:
                self.getHeight(root.right)

            Solution.currentHeight -= 1

        elif Solution.currentHeight > Solution.maxHeight:
            Solution.maxHeight = Solution.currentHeight

        return Solution.maxHeight


# Immutable HackerRank code below
T = int(input())
myTree = Solution()
root = None
for i in range(T):
    data = int(input())
    root = myTree.insert(root, data)
height = myTree.getHeight(root)
print(height)
