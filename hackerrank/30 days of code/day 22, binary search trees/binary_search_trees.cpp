// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

#include <iostream>
#include <memory>
using namespace std;

typedef struct Node {
    int data{};
    shared_ptr<Node> left, right;

    explicit Node(int d): data{d} {}
} Node;

shared_ptr<Node> read_tree();
shared_ptr<Node> insert_node(shared_ptr<Node> root, int data);
int get_height(const shared_ptr<Node>& root);

int main()
{
    shared_ptr root{read_tree()};
    cout << get_height(root);
    return 0;
}

shared_ptr<Node> read_tree()
{
    int n;
    cin >> n;
    shared_ptr<Node> root;
    for (int data; n-- && cin >> data;)
        root = insert_node(root, data);
    return root;
}

shared_ptr<Node> insert_node(shared_ptr<Node> root, int data)
{
    if (!root)
        return make_shared<Node>(data);
    if (data <= root->data)
        root->left = insert_node(root->left, data);
    else
        root->right = insert_node(root->right, data);
    return root;
}

int get_height(const shared_ptr<Node>& root)
{
    if (!root)
        return -1;
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return max(left_height, right_height) + 1;
}
