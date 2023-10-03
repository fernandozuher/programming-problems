# https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

def main():

    my_list = Solution()
    T = int(input())
    head = None

    for i in range(T):
        n = int(input())
        head = my_list.insert(head, n)

    my_list.display(head)


class Node:

    def __init__(self, data):

        self.data = data
        self.next = None


class Solution:

    def display(self, head):

        current = head
        while current:
            print(current.data, end=' ')
            current = current.next


    def insert(self, head, data):

        if head:
            start = head
            while start.next:
                start = start.next
            start.next = Node(data)
        else:
            start = Node(data)
            head = start

        return head


if __name__ == '__main__':
    main()
