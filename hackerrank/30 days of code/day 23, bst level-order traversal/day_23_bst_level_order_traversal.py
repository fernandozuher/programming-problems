import sys


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
    def levelOrder(self, root):

        from collections import deque

        if not root:
            return

        myQueue = deque()
        myQueue.append(root)
        print(myQueue[0].data, end=" ")

        while len(myQueue):

            if myQueue[0].left:
                myQueue.append(myQueue[0].left)
                print(myQueue[0].left.data, end=" ")

            if myQueue[0].right:
                myQueue.append(myQueue[0].right)
                print(myQueue[0].right.data, end=" ")

            myQueue.popleft()


# Immutable HackerRank code below
T = int(input())
myTree = Solution()
root = None
for i in range(T):
    data = int(input())
    root = myTree.insert(root, data)
myTree.levelOrder(root)
