// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

[[nodiscard]] Node *read_tree();
[[nodiscard]] Node *insert_node(Node *root, int data);
[[nodiscard]] Node *new_node(int data);
void level_order(Node *root);
Node *free_tree(Node *root);

int main()
{
    Node *root = read_tree();
    level_order(root);
    free_tree(root);
    return 0;
}

[[nodiscard]] Node *read_tree()
{
    Node *root = nullptr;
    int n;
    scanf("%d", &n);
    for (int data; n--;) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    return root;
}

[[nodiscard]] Node *insert_node(Node *root, int data)
{
    if (!root)
        return new_node(data);
    if (data <= root->data)
        root->left = insert_node(root->left, data);
    else
        root->right = insert_node(root->right, data);
    return root;
}

[[nodiscard]] Node *new_node(int data)
{
    auto node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

void level_order(Node *root)
{
    if (!root)
        return;
    constexpr int max_input = 20;
    Node *queue[max_input];
    queue[0] = root;

    for (int i = 0, n = 1; i < n; ++i) {
        Node *current = queue[i];
        printf("%d ", current->data);
        if (current->left)
            queue[n++] = current->left;
        if (current->right)
            queue[n++] = current->right;
    }
}

Node *free_tree(Node *root)
{
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
    return nullptr;
}
