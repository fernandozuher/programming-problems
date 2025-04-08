// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

[[nodiscard]] Node *read_tree();
[[nodiscard]] Node *insert_node(Node *root, int data);
[[nodiscard]] Node *new_node(int data);
int get_height(const Node *root);
void get_height_in_place_by_traversal(const Node *root, int current_height, int *max_height);
bool is_leaf(const Node *root);
int max(int a, int b);
Node *free_tree(Node *root);

int main()
{
    Node *root = read_tree();
    printf("%d", get_height(root));
    free_tree(root);
    return 0;
}

[[nodiscard]] Node *read_tree()
{
    int n;
    scanf("%d", &n);
    Node *root = nullptr;
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

int get_height(const Node *root)
{
    if (!root)
        return -1;
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return max(left_height, right_height) + 1;
}

inline int max(int a, int b)
{
    return a >= b ? a : b;
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
