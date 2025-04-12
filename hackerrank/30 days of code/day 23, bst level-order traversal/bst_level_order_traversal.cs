// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

using static System.Console;

record Node(int Data)
{
    public Node? Left { get; set; }
    public Node? Right { get; set; }
}

static class Solution
{
    static void Main()
    {
        Node? root = ReadTree();
        LevelOrder(root);
    }

    private static Node? ReadTree()
    {
        Node? root = null;
        for (int n = int.Parse(ReadLine()); n-- > 0;)
        {
            int data = int.Parse(ReadLine());
            root = InsertNode(root, data);
        }
        return root;
    }

    private static Node InsertNode(Node? root, int data)
    {
        if (root == null)
            return new Node(data);
        if (data <= root.Data)
            root.Left = InsertNode(root.Left, data);
        else
            root.Right = InsertNode(root.Right, data);
        return root;
    }

    private static void LevelOrder(Node? root)
    {
        if (root == null)
            return;

        var myQueue = new Queue<Node>();
        myQueue.Enqueue(root);
        while (myQueue.Count != 0)
        {
            var current = myQueue.Dequeue();
            Write(current.Data + " ");
            if (current.Left != null)
                myQueue.Enqueue(current.Left);
            if (current.Right != null)
                myQueue.Enqueue(current.Right);
        }
    }
}
