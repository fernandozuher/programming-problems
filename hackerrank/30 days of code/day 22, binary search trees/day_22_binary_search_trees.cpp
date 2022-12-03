#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class Solution
{
public:

    Node* insert(Node* root, int data) {

        if (!root)
            return new Node(data);
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    static int get_height(Node *root) {
        static int current_height {}, max_height {};

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
};

int main() {
    Solution my_tree;
    Node* root {nullptr};
    int n;
    cin >> n;

    for (int data; cin >> data; root = my_tree.insert(root, data));
    
    cout << Solution::get_height(root);

    return 0;
}
