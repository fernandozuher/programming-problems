// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node* insert(Node *root, int data);
    Node* new_node(int data);
void level_order(Node *root);

int main()
{
    Node *root = NULL;
    int n_tests, data;
    scanf("%d", &n_tests);

    while (n_tests--) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    level_order(root);

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

        Node* new_node(const int data)
        {
            Node *node = (Node*) malloc(sizeof(Node));
            node->left = node->right = NULL;
            node->data = data;
            return node;
        }
// Immutable HackerRank code above

    void level_order(Node *root)
    {
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
