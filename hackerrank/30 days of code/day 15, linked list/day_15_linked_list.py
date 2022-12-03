class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def display(self, head):

        current = head
        while current:
            print(current.data, end=" ")
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


mylist = Solution()

T = int(input())
head = None

for i in range(T):
    head = mylist.insert(head, int(input()))

mylist.display(head)
