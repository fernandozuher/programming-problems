# https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

from collections import deque

def main():

    n_tests = int(input())
    my_tree = Solution()
    root = None

    for i in range(n_tests):
        data = int(input())
        root = my_tree.insert(root, data)

    my_tree.level_order(root)


class Tree:

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


    def level_order(self, root):

        if not root:
            return

        my_queue = deque()
        my_queue.append(root)
        print(my_queue[0].data, end=' ')

        while len(my_queue):

            if my_queue[0].left:
                my_queue.append(my_queue[0].left)
                print(my_queue[0].left.data, end=" ")

            if my_queue[0].right:
                my_queue.append(my_queue[0].right)
                print(my_queue[0].right.data, end=" ")

            my_queue.popleft()


class Node:

    def __init__(self, data):

        self.right = self.left = None
        self.data = data


if __name__ == '__main__':
    main()
