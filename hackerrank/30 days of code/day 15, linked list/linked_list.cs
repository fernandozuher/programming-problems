// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

using System;

public class Solution
{
    public static Node insert(Node head, int data)
    {
        Node start;

        if (head != null)
        {
            start = head;
            for ( ; start.next != null; start = start.next);
            start.next = new Node(data);
        }
        else
        {
            start = new Node(data);
            head = start;
        }

        return head;
    }

    public static void display(Node head)
    {
        Node start = head;

        while (start != null)
        {
            Console.Write(start.data + " ");
            start = start.next;
        }
    }

    public static void Main()
    {
        Node head = null;
        int T = Int32.Parse(Console.ReadLine());

        while (T-- > 0)
            head = insert(head, Int32.Parse(Console.ReadLine()));

        display(head);
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
