# https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

def main():

    T = int(input())
    my_tree = Solution()
    root = None

    for i in range(T):
        data = int(input())
        root = my_tree.insert(root, data)

    height = my_tree.get_height(root)
    print(height)


class Solution:

    current_height = 0
    max_height = 0

    def insert(self, root, data):

        if not root:
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

    def get_height(self, root):

        if root.left or root.right:
            Solution.current_height += 1

            if root.left:
                self.get_height(root.left)
            if root.right:
                self.get_height(root.right)

            Solution.current_height -= 1

        elif Solution.current_height > Solution.max_height:
            Solution.max_height = Solution.current_height

        return Solution.max_height

# Immutable HackerRank code below
class Node:

    def __init__(self, data):

        self.data = data
        self.right = self.left = None


if __name__  == '__main__':
    main
