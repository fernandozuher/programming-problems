// https://www.hackerrank.com/challenges/tree-postorder-traversal/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<class T>
struct Node {
    T data;
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;

    explicit Node(T data) : data{ move(data) } {}
};

template<class T>
concept Readable = requires(istream& is, T& value) { is >> value; };

template<Readable T>
T read_as()
{
    T x;
    if (cin >> x)
        return x;
    throw invalid_argument("Failed to read value.");
}

struct read {
    template<Readable T>
    operator T() const {
        return read_as<T>();
    }
};

template<ranges::range C>
C read_to(int n)
{
    using T = ranges::range_value_t<C>;
    return views::iota(0, n)
        | views::transform([](...) { return read_as<T>(); })
        | ranges::to<C>();
}

template<class T>
shared_ptr<Node<T>> insert(const T& data, const shared_ptr<Node<T>>& node = nullptr)
{
    if (!node)
        return make_shared<Node<T>>(data);

    if (data <= node->data)
        node->left = insert(data, node->left);
    else
        node->right = insert(data, node->right);

    return node;
}

template<ranges::range C, class T = ranges::range_value_t<C>>
shared_ptr<Node<T>> to_binary_tree(const C& c)
{
    shared_ptr<Node<T>> root;
    for (const auto& x : c) {
        root = insert(x, root);
    }
    return root;
}

// n = number of nodes
// T: O(n)
// S:
//   h = height of the tree
//   O(h) recursion call stack, extra space 
//   Worst case: h = n => O(n)
template<class T>
void post_order(const shared_ptr<Node<T>>& node)
{
    if (node) {
        post_order(node->left);
        post_order(node->right);
        print("{} ", node->data);
    }
}

int main()
{
    int n{ read() };
    auto arr{ read_to<vector<int>>(n) };
    auto root{ to_binary_tree(arr) };
    post_order(root);
    return 0;
}
