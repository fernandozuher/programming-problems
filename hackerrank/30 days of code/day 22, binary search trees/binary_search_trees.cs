// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

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
        Node root = ReadTree();
        WriteLine(GetHeight(root));
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

    private static int GetHeight(Node? root)
    {
        if (root == null)
            return -1;
        int leftHeight = GetHeight(root.Left);
        int rightHeight = GetHeight(root.Right);
        return Math.Max(leftHeight, rightHeight) + 1;
    }
}
