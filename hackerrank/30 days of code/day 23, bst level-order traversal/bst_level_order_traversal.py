# https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

from dataclasses import dataclass
from collections import deque


def main():
    root = read_tree()
    level_order(root)


def read_tree():
    root = None
    n = int(input())
    for _ in range(n):
        data = int(input())
        root = insert_node(root, data)
    return root


def insert_node(root, data):
    if root is None:
        return Node(data)
    if data <= root.data:
        root.left = insert_node(root.left, data)
    else:
        root.right = insert_node(root.right, data)
    return root


@dataclass
class Node:
    data: int
    left: 'Node' = None
    right: 'Node' = None


def level_order(root):
    if not root:
        return

    my_queue = deque()
    my_queue.append(root)
    while len(my_queue):
        current = my_queue.popleft()
        print(current.data, end=" ")
        if current.left:
            my_queue.append(current.left)
        if current.right:
            my_queue.append(current.right)


if __name__ == '__main__':
    main()
