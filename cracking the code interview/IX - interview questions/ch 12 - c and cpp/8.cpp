// From C++23

#include <iostream>
#include <print>

using namespace std;

struct Node {
    int data;
    Node* a{};
    Node* b{};
};

Node* copy_node(const Node* node);
void print_node(const Node* node);
Node* free_node(Node* node);

int main()
{
    auto node_a = new Node{1};
    node_a->a = new Node{2};
    node_a->b = new Node{3};
    cout << "Node a: ";
    print_node(node_a);

    auto node_b{copy_node(node_a)};
    cout << "Node b: ";
    print_node(node_b);

    node_a->data = 11;
    node_a->a->data = 22;
    node_a->b->data = 33;
    cout << "\nNode a: ";
    print_node(node_a);

    cout << "Node b: ";
    print_node(node_b);

    node_a = free_node(node_a);
    node_b = free_node(node_b);

    return 0;
}

Node* copy_node(const Node* node)
{
    auto new_node = new Node{*node};
    if (node->a)
        new_node->a = copy_node(node->a);
    if (node->b)
        new_node->b = copy_node(node->b);
    return new_node;
}

void print_node(const Node* node)
{
    println("{}: {}, {}", node->data, node->a->data, node->b->data);
}

Node* free_node(Node* node)
{
    if (node->a)
        node->a = free_node(node->a);
    if (node->b)
        node->b = free_node(node->b);
    free(node);
    return nullptr;
}
