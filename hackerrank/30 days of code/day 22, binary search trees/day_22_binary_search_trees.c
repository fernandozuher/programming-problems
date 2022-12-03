#include <stdio.h>
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

int getHeight(Node *root) {
    static int current_height = 0, max_height = 0;

    if (root->left || root->right) {
        ++current_height;
        if (root->left)
            getHeight(root->left);
        if (root->right)
            getHeight(root->right);
        --current_height;
    }
    else if (current_height > max_height)
        max_height = current_height;
    
    return max_height;
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
    int height=getHeight(root);
    printf("%d",height);
    return 0;
    
}