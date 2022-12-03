using System;
class Node{
    public Node left,right;
    public int data;
    public Node(int data){
        this.data=data;
        left=right=null;
    }
}

class Solution {
// Immutable HackerRank code above

    private static int currentHeight = 0, maxHeight = 0;

    static int getHeight(Node root) {
        
        if (root.left != null || root.right != null) {
            ++currentHeight;
            if (root.left != null)
                getHeight(root.left);
            if (root.right != null)
                getHeight(root.right);
            --currentHeight;
        }
        else if (currentHeight > maxHeight)
            maxHeight = currentHeight;
        
        return maxHeight;
    }

    // Immutable HackerRank code below

    static Node insert(Node root, int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    static void Main(String[] args){
        Node root=null;
        int T=Int32.Parse(Console.ReadLine());
        while(T-->0){
            int data=Int32.Parse(Console.ReadLine());
            root=insert(root,data);            
        }
        int height=getHeight(root);
        Console.WriteLine(height);
        
    }
}