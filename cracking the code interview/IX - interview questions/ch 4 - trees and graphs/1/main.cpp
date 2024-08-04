// From C++23

#include <iostream>
#include <print>
#include <ranges>
#include <unordered_set>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = int>
struct Graph_Node {
    T data{};
    vector<shared_ptr<Graph_Node>> children;
    explicit Graph_Node(const T& data): data{data} {}
};

template<class T = int>
struct Graph {
    vector<shared_ptr<Graph_Node<T>>> nodes;
};

template<class T = int>
using node_and_parents = tuple<shared_ptr<Graph_Node<T>>, vector<shared_ptr<Graph_Node<T>>>>;

template<class T = int>
Graph<T> initialize_graph();
template<class T = int>
vector<shared_ptr<Graph_Node<T>>> nodes_to_look_for(const Graph<T>& graph);
template<class T = int>
node_and_parents<T> breadth_first_search(const shared_ptr<Graph_Node<T>>& root,
                                         const shared_ptr<Graph_Node<T>>& wanted);

int main()
{
    const auto graph{initialize_graph()};
    for (const auto root{graph.nodes.front()}; const auto& wanted : nodes_to_look_for(graph)) {
        print("Look for node {}, ", wanted->data);
        cout << wanted.get() << '\n';

        if (const auto [node, parents]{breadth_first_search(root, wanted)}; node) {
            print("\nFOUND: ");
            for (const auto& x : parents)
                print("{} -> ", x->data);
            println("{}", node->data);
        }
        else
            println("NOT FOUND");
        println("");
    }
    return 0;
}

template<class T>
Graph<T> initialize_graph()
{
    vector<shared_ptr<Graph_Node<>>> nodes(10);
    for (auto [i, node] : nodes | views::enumerate)
        node = make_shared<Graph_Node<>>(i);

    // 0: 1, 5
    nodes.at(0)->children.push_back(nodes.at(1));
    nodes.at(0)->children.push_back(nodes.at(5));

    // 1: 2
    nodes.at(1)->children.push_back(nodes.at(2));
    // 2: 3
    nodes.at(2)->children.push_back(nodes.at(3));
    // 3: 4
    nodes.at(3)->children.push_back(nodes.at(4));

    // 4:

    // 5: 6, 7
    nodes.at(5)->children.push_back(nodes.at(6));
    nodes.at(5)->children.push_back(nodes.at(7));

    // 6: 1
    nodes.at(6)->children.push_back(nodes.at(1));

    // 7: 8, 9
    nodes.at(7)->children.push_back(nodes.at(8));
    nodes.at(7)->children.push_back(nodes.at(9));

    // 8:
    // 9:

    return Graph{nodes};
}

template<class T>
vector<shared_ptr<Graph_Node<T>>> nodes_to_look_for(const Graph<T>& graph)
{
    return {make_shared<Graph_Node<>>(11), graph.nodes.at(7), graph.nodes.front()};
}

template<class T>
node_and_parents<T> breadth_first_search(const shared_ptr<Graph_Node<T>>& root, const shared_ptr<Graph_Node<T>>& wanted)
{
    println("Visiting nodes...");
    if (root == wanted) {
        print("{} ", root->data);
        return {root, {}};
    }

    Queue<node_and_parents<T>> queue;
    queue.add({root, {}});
    unordered_set<Graph_Node<T>*> marked{root.get()};

    while (!queue.is_empty()) {
        auto [node, parents]{queue.remove()};
        print("{} ", node->data);

        if (node == wanted)
            return {node, parents};

        parents.push_back(node);
        for (const auto& x : node->children)
            if (!marked.contains(x.get())) {
                marked.insert(x.get());
                queue.add({x, parents});
            }
    }

    return {nullptr, {}};
}
