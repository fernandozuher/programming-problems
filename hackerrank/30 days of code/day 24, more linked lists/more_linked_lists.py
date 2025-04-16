# https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

from dataclasses import dataclass


def main():
    head = read_list()
    remove_consecutive_duplicates(head)
    display(head)


def read_list():
    n = int(input())
    head = None
    tail = None

    for _ in range(0, n):
        new_node = Node(int(input()))
        if head is None:
            head = tail = new_node
        else:
            tail.next = new_node
            tail = new_node
    return head


@dataclass
class Node:
    data: int
    next: 'Node' = None


def remove_consecutive_duplicates(head):
    node = head
    while node and node.next:
        if node.data == node.next.data:
            node.next = node.next.next
        else:
            node = node.next


def display(head):
    node = head
    while node:
        print(node.data, end=' ')
        node = node.next


if __name__ == '__main__':
    main()
