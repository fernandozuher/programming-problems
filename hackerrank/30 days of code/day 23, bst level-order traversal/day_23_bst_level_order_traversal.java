import java.util.*;

class Node {
    Node left, right;
    int data;
    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class Solution {
    static void levelOrder(Node root) {
        if (root == null)
            return;
        
        var myQueue = new LinkedList<Node>();
        myQueue.add(root);
        System.out.print(myQueue.peek().data + " ");

        for ( ; !myQueue.isEmpty(); myQueue.remove()) {
            
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

    public static Node insert(Node root, int data) {
        if (root == null)
            return new Node(data);
        else {
            Node cur;
            if(data <= root.data){
                cur = insert(root.left, data);
                root.left = cur;
            }
            else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Node root = null;
        for (sc.nextInt(); sc.hasNext(); root = insert(root, sc.nextInt()));
        levelOrder(root);
    }
}
