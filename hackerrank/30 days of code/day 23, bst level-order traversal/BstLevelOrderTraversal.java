// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

import java.util.Scanner;
import java.util.LinkedList;

public class BstLevelOrderTraversal {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        Node root = null;
        for (int _n = scan.nextInt(); scan.hasNext(); root = Tree.insert(root, scan.nextInt()));
        Tree.levelOrder(root);
    }
}

    class Tree {
        public static Node insert(Node root, final int data) {
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

        public static void levelOrder(Node root) {
            if (root == null)
                return;

            var myQueue = new LinkedList<Node>();
            myQueue.add(root);
            System.out.print(myQueue.peek().data + " ");

            for (; !myQueue.isEmpty(); myQueue.remove()) {

                if (myQueue.peek().left != null) {
                    myQueue.add(myQueue.peek().left);
                    System.out.print(myQueue.peek().left.data + " ");
                }

                if (myQueue.peek().right != null) {
                    myQueue.add(myQueue.peek().right);
                    System.out.print(myQueue.peek().right.data + " ");
                }
            }
        }
    }

        class Node {
            public Node left, right;
            public int data;
            public Node(final int data) {
                this.data = data;
                left = right = null;
            }
        }
