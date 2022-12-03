#include <iostream>
#include <queue>

using namespace std;

class Node
{
    public:
        int data;
        Node *left, *right;
        Node(int d): data{d}, left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
        static Node* insert(Node *root, int data) {
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

        static void level_order(Node *root) {
            if (!root)
                return;
            
            queue<Node*> my_queue;
            my_queue.push(root);
            cout << my_queue.front()->data << " ";

            for ( ; !my_queue.empty(); my_queue.pop()) {
                
                if (my_queue.front()->left)
                    my_queue.push(my_queue.front()->left), cout << my_queue.front()->left->data << " ";

                if (my_queue.front()->right)
                    my_queue.push(my_queue.front()->right), cout << my_queue.front()->right->data << " ";
            }
        }
};

int main() {
    Node* root = nullptr;
    int data;

    for (cin >> data; cin >> data; root = Solution::insert(root, data));
    Solution::level_order(root);

    return 0;
}
