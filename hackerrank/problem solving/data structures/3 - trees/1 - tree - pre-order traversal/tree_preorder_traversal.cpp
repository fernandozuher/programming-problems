// https://www.hackerrank.com/challenges/tree-preorder-traversal/problem?isFullScreen=true

import <iostream>;
import <memory>;

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left {};
    shared_ptr<Node> right {};

    Node(const int data): data{data} {}
};

shared_ptr<Node> insert_node(const shared_ptr<Node>& node, const int data);
void pre_order(const shared_ptr<Node>& node);

int main()
{
    int n;
    cin >> n;

    shared_ptr<Node> root {};
    for (int data; n-- && cin >> data;)
        root = insert_node(root, data);

    pre_order(root);

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

    void pre_order(const shared_ptr<Node>& node)
    {
        if (node) {
            cout << node->data << ' ';
            pre_order(node->left);
            pre_order(node->right);
        }
    }
