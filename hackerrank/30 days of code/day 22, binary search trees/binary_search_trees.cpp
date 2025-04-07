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
void get_height(const shared_ptr<Node>& root, int current_height, const shared_ptr<int>& max_height);
bool is_leaf(const shared_ptr<Node>& root);

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

    shared_ptr<Node> node;
    if (data <= root->data) {
        node = insert_node(root->left, data);
        root->left = node;
    } else {
        node = insert_node(root->right, data);
        root->right = node;
    }
    return root;
}

int get_height(const shared_ptr<Node>& root)
{
    auto max_height{make_shared<int>()};
    get_height(root, 0, max_height);
    return *max_height;
}

void get_height(const shared_ptr<Node>& root, int current_height, const shared_ptr<int>& max_height)
{
    if (!root)
        return;
    if (is_leaf(root)) {
        *max_height = max(current_height, *max_height);
        return;
    }
    get_height(root->left, current_height + 1, max_height);
    get_height(root->right, current_height + 1, max_height);
}

bool is_leaf(const shared_ptr<Node>& root)
{
    return !root->left && !root->right;
}
