// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

#include <iostream>
#include <memory>
#include <queue>

using namespace std;

typedef struct Node {
    int data;
    shared_ptr<Node> left, right;
    explicit Node(int d): data{d} {}
} Node;

shared_ptr<Node> read_tree();
shared_ptr<Node> insert_node(shared_ptr<Node> root, int data);
void level_order(const shared_ptr<Node>& root);

int main()
{
    shared_ptr root{read_tree()};
    level_order(root);
    return 0;
}

shared_ptr<Node> read_tree()
{
    shared_ptr<Node> root;
    int n;
    cin >> n;
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

void level_order(const shared_ptr<Node>& root)
{
    if (!root)
        return;

    queue<shared_ptr<Node>> my_queue;
    my_queue.push(root);
    for (; !my_queue.empty(); my_queue.pop()) {
        cout << my_queue.front()->data << " ";
        if (my_queue.front()->left)
            my_queue.push(my_queue.front()->left);
        if (my_queue.front()->right)
            my_queue.push(my_queue.front()->right);
    }
}
