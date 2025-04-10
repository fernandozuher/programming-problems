# https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

from dataclasses import dataclass


def main():
    root = read_tree()
    print(get_height(root))


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


def get_height(root):
    if root is None:
        return -1
    left_height = get_height(root.left)
    right_height = get_height(root.right)
    return max(left_height, right_height) + 1


if __name__ == '__main__':
    main()
