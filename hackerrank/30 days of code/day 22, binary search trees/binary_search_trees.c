// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node* insert(Node *root, int data);
    Node* new_node(int data);
int get_height(Node *root);

int main()
{
    Node *root = NULL;
    int T, data;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int height = get_height(root);
    printf("%d", height);

    return 0;
}

    Node* insert(Node *root, int data)
    {
        if (!root)
            return new_node(data);
        else {
            Node *cur;

            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
        }

        return root;
    }

        Node* new_node(int data)
        {
            Node *node = (Node*) malloc(sizeof(Node));
            node->left = node->right = NULL;
            node->data = data;
            return node;
        }    
// Immutable HackerRank code ABOVE

    int get_height(Node *root)
    {
        static int current_height = 0, max_height = 0;

        if (root->left || root->right) {
            ++current_height;

            if (root->left)
                get_height(root->left);
            if (root->right)
                get_height(root->right);

            --current_height;
        }
        else if (current_height > max_height)
            max_height = current_height;

        return max_height;
    }
