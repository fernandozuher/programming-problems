// https://www.hackerrank.com/challenges/is-binary-search-tree/problem?isFullScreen=true

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
struct Node {
    int data;
    Node* left;
    Node* right;
}
*/

bool checkBST(Node* root)
{
    return in_order(root);
}

    bool in_order(Node* root)
    {
        static int previous {-1};
        return !root || in_order(root->left) && is_previous_less_than_current(previous, root->data) && in_order(root->right);
    }

        bool is_previous_less_than_current(int &previous, const int current)
        {
            if (previous != -1 && previous >= current)
                return false;
            previous = current;
            return true;
        }
