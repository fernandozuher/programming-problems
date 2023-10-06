// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public static void Main()
    {
        Node root = null;
        int nTests = int.Parse(Console.ReadLine());

        while (nTests-- > 0)
        {
            int data = int.Parse(Console.ReadLine());
            root = Tree.Insert(root, data);
        }

        Tree.LevelOrder(root);
    }
}

    public class Tree
    {
        public static Node Insert(Node root, int data)
        {
            if (root == null)
                return new Node(data);
            else
            {
                Node cur;
                if (data <= root.data)
                {
                    cur = Insert(root.left, data);
                    root.left = cur;
                }
                else
                {
                    cur = Insert(root.right, data);
                    root.right = cur;
                }
                return root;
            }
        }

        public static void LevelOrder(Node root)
        {
            if (root == null)
                return;

            var myQueue = new Queue<Node>();
            myQueue.Enqueue(root);
            Console.Write(myQueue.Peek().data + " ");

            for (; myQueue.Count() != 0; myQueue.Dequeue())
            {
                if (myQueue.Peek().left != null)
                {
                    myQueue.Enqueue(myQueue.Peek().left);
                    Console.Write(myQueue.Peek().left.data + " ");
                }

                if (myQueue.Peek().right != null)
                {
                    myQueue.Enqueue(myQueue.Peek().right);
                    Console.Write(myQueue.Peek().right.data + " ");
                }
            }
        }
    }

        public class Node
        {
            public Node left, right;
            public int data;
            public Node(int data)
            {
                this.data = data;
                left = right = null;
            }
        }
