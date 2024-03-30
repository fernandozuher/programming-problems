// https://www.hackerrank.com/challenges/tree-postorder-traversal/problem?isFullScreen=true

#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left {};
    shared_ptr<Node> right {};

    Node(const int data): data{data} {}
};

shared_ptr<Node> insert_node(const shared_ptr<Node>& node, const int data);
void post_order(const shared_ptr<Node>& root);

int main()
{
    int n;
    cin >> n;

    shared_ptr<Node> root {};
    for (int data; n-- && cin >> data;)
        root = insert_node(root, data);

    post_order(root);

    return 0;
}

    shared_ptr<Node> insert_node(const shared_ptr<Node>& node, const int data)
    {
        if (!node)
            return shared_ptr<Node> {new Node{data}};

        if (shared_ptr<Node> current; data <= node->data) {
            current = insert_node(node->left, data);
            node->left = current;
        } else {
            current = insert_node(node->right, data);
            node->right = current;
        }
        return node;
    }

    void post_order(const shared_ptr<Node>& root)
    {
        if (root) {
            post_order(root->left);
            post_order(root->right);
            cout << root->data << ' ';
        }
    }
