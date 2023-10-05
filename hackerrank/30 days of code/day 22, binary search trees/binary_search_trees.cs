// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

using System;

public class Solution
{
    private static int _currentHeight = 0;
    private static int _maxHeight = 0;

    public static void Main()
    {
        Node root = null;
        int T = int.Parse(Console.ReadLine());

        while (T-- > 0)
        {
            int data = int.Parse(Console.ReadLine());
            root = _insert(root, data);
        }

        Console.WriteLine(_getHeight(root));
    }

        private static Node _insert(Node root, int data)
        {
            if (root == null)
                return new Node(data);
            else
            {
                Node cur;

                if (data <= root.data)
                {
                    cur = _insert(root.left, data);
                    root.left = cur;
                }
                else
                {
                    cur = _insert(root.right, data);
                    root.right = cur;
                }

                return root;
            }
        }

        private static int _getHeight(Node root)
        {
            if (root.left != null || root.right != null)
            {
                ++_currentHeight;

                if (root.left != null)
                    _getHeight(root.left);
                if (root.right != null)
                    _getHeight(root.right);

                --_currentHeight;
            }
            else if (_currentHeight > _maxHeight)
                _maxHeight = _currentHeight;

            return _maxHeight;
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
