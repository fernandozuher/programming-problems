// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
    }
}

class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        Node root = readTree();
        levelOrder(root);
    }

    private static Node readTree() {
        Node root = null;
        for (int n = scan.nextInt(); n-- > 0; ) {
            int data = scan.nextInt();
            root = insertNode(root, data);
        }
        return root;
    }

    private static Node insertNode(Node root, int data) {
        if (root == null)
            return new Node(data);
        if (data <= root.data)
            root.left = insertNode(root.left, data);
        else
            root.right = insertNode(root.right, data);
        return root;
    }

    public static void levelOrder(Node root) {
        if (root == null)
            return;

        var myQueue = new LinkedList<Node>();
        myQueue.add(root);
        for (; !myQueue.isEmpty(); myQueue.remove()) {
            Node current = myQueue.peek();
            System.out.print(current.data + " ");
            if (current.left != null) myQueue.add(current.left);
            if (current.right != null) myQueue.add(current.right);
        }
    }
}
