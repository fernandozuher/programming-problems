# https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

def main():

    my_list = MoreLinkedLists()
    n_tests = int(input())
    head = None

    for _ in range(n_tests):
        data = int(input())
        head = my_list.insert(head, data)

    head = my_list.remove_duplicates(head)
    my_list.display(head)


class MoreLinkedLists:

    def insert(self, head, data):

        p = Node(data)

        if head == None:
            head = p
        elif head.next == None:
            head.next = p
        else:
            start = head
            while start.next != None:
                start = start.next
            start.next = p

        return head


    def remove_duplicates(self, head):

        original = head

        while head.next:
            if head.data == head.next.data:
                head.next = head.next.next
            else:
                head = head.next

        return original


    def display(self, head):

        current = head
        while current:
            print(current.data, end=' ')
            current = current.next


class Node:

    def __init__(self, data):

        self.data = data
        self.next = None


if __name__ == '__main__':
    main()
