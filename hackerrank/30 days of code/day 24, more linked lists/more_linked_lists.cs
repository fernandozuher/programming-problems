// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        Node head = null;
        for (int nTests = int.Parse(Console.ReadLine()); nTests-- > 0;) {
            int data = int.Parse(Console.ReadLine());
            head = Insert(head, data);
        }
        head = RemoveDuplicates(head);
        Display(head);
    }

        public static Node Insert(Node head, int data)
        {
            Node p = new Node(data);

            if (head == null)
                head = p;
            else if (head.next == null)
                head.next = p;
            else
            {
                Node start = head;
                while (start.next != null)
                    start = start.next;
                start.next = p;

            }

            return head;
        }

        public static Node RemoveDuplicates(Node head)
        {
            Node original = head;
            while (head.next != null) {
                if (head.data == head.next.data)
                    head.next = head.next.next;
                else
                    head = head.next;
            }
            return original;
        }

        public static void Display(Node head)
        {
            Node start = head;
            while (start != null)
            {
                Console.Write(start.data + " ");
                start = start.next;
            }
        }
}

    public class Node
    {
        public int data;
        public Node next;
        public Node(int d)
        {
            data = d;
            next = null;
        }
    }
