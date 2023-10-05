// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

import java.util.Scanner;

class Node {
    public Node left, right;
    public int data;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class Solution {
    private static int currentHeight = 0, maxHeight = 0;

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        Node root = null;

        for (int data; T-- > 0;) {
            data = scan.nextInt();
            root = insert(root, data);
        }

        System.out.println(getHeight(root));
    }

        private static Node insert(Node root, final int data) {
            if (root == null)
                return new Node(data);
            else {
                Node cur;

                if (data <= root.data) {
                    cur = insert(root.left, data);
                    root.left = cur;
                } else {
                    cur = insert(root.right, data);
                    root.right = cur;
                }

                return root;
            }
        }

        private static int getHeight(final Node root) {
            if (root.left != null || root.right != null) {
                ++currentHeight;

                if (root.left != null)
                    getHeight(root.left);
                if (root.right != null)
                    getHeight(root.right);

                --currentHeight;

            } else if (currentHeight > maxHeight)
                maxHeight = currentHeight;

            return maxHeight;
        }
}
