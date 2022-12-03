using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Node{
    public Node left,right;
    public int data;
    public Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

// Immutable HackerRank code above

    static void levelOrder(Node root) {
        if (root == null)
            return;
        
        var myQueue = new Queue<Node>();
        myQueue.Enqueue(root);
        Console.Write(myQueue.Peek().data + " ");

        for ( ; myQueue.Count() != 0; myQueue.Dequeue()) {
            
            if (myQueue.Peek().left != null) {
                myQueue.Enqueue(myQueue.Peek().left);
                Console.Write(myQueue.Peek().left.data + " ");
            }

            if (myQueue.Peek().right != null) {
                myQueue.Enqueue(myQueue.Peek().right);
                Console.Write(myQueue.Peek().right.data + " ");
            }
        }
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
        while(T-.0){
            int data=Int32.Parse(Console.ReadLine());
            root=insert(root,data);            
        }
        levelOrder(root);
        
    }
}