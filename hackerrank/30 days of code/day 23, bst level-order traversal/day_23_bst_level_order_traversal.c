#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}
// Immutable HackerRank code above

void levelOrder(Node* root) {
    if (!root)
        return;

    Node *queue[20];
    queue[0] = root;
    printf("%d ", queue[0]->data);

    for (int i = 0, n = 1; i < n; ++i) {
        queue[i]->left && (queue[n++] = queue[i]->left) && printf("%d ", queue[i]->left->data);
        queue[i]->right && (queue[n++] = queue[i]->right) && printf("%d ", queue[i]->right->data);
    }
}

// Immutable HackerRank code below
Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    return 0;
    
}