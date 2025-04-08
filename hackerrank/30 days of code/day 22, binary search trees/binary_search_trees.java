// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

import java.util.Scanner;

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
        System.out.println(getHeight(root));
    }

    private static Node readTree() {
        int n = scan.nextInt();
        Node root = null;
        for (int data; n-- > 0; ) {
            data = scan.nextInt();
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

    private static int getHeight(Node root) {
        if (root == null)
            return -1;
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
