// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <print>
#include <stdexcept>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Queue.h"

using namespace std;
using namespace queue_exercises;

template<class T = char>
struct Graph_Node {
    T data;
    vector<shared_ptr<Graph_Node>> adjacents;
};

template<class T = char>
using ptr_node = shared_ptr<Graph_Node<T>>;

template<class T = char>
struct Graph {
    vector<ptr_node<T>> nodes;
};

template<class T = char>
pair<vector<T>, vector<pair<T, T>>> data_test();
template<class T = char>
vector<T> build_order(const vector<T>& projects, const vector<pair<T, T>>& dependencies);
template<class T = char>
vector<ptr_node<T>> create_nodes_from(const vector<T>& projects);
template<class T = char>
Graph<T> create_graph_from(const vector<ptr_node<T>>& nodes, const vector<pair<T, T>>& dependencies);
template<class T = char>
vector<T> traversal(const Graph<T>& graph);

int main()
{
    const auto [projects, dependencies]{data_test()};
    print("Projects: ");
    ranges::copy(projects, ostream_iterator<char>(cout, " "));
    println("");

    print("Dependencies: ");
    char parent, child;
    for (const auto& parent_child : dependencies | views::take(dependencies.size() - 1)) {
        tie(parent, child) = parent_child;
        print("({}, {}), ", parent, child);
    }
    tie(parent, child) = dependencies.back();
    println("({}, {})", parent, child);

    try {
        print("Build order: ");
        ranges::copy(build_order(projects, dependencies), ostream_iterator<char>(cout, " "));
    }
    catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
    }

    return 0;
}

template<class T>
pair<vector<T>, vector<pair<T, T>>> data_test()
{
    return {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}}
    };
}

template<class T>
vector<T> build_order(const vector<T>& projects, const vector<pair<T, T>>& dependencies)
{
    auto nodes{create_nodes_from(projects)};
    auto graph{create_graph_from(nodes, dependencies)};
    return traversal(graph);
}

template<class T>
vector<ptr_node<T>> create_nodes_from(const vector<T>& projects)
{
    vector<ptr_node<T>> nodes(projects.size());
    const auto create_node{[](const auto& data) { return make_shared<Graph_Node<T>>(data); }};
    ranges::transform(projects, nodes.begin(), create_node);
    return nodes;
}

template<class T>
Graph<T> create_graph_from(const vector<ptr_node<T>>& nodes, const vector<pair<T, T>>& dependencies)
{
    unordered_map<T, ptr_node<T>> data_to_node;
    for (const auto& node : nodes)
        data_to_node[node->data] = node;

    for (const auto& [parent, child] : dependencies)
        data_to_node[parent]->adjacents.push_back(data_to_node[child]);

    return Graph<T>{nodes};
}

template<class T>
vector<T> traversal(const Graph<T>& graph)
{
    unordered_set<T> nodes_with_parents;
    for (const auto& node : graph.nodes)
        for (const auto& adj : node->adjacents)
            nodes_with_parents.insert(adj->data);

    vector<T> result;
    unordered_set<T> visited;
    Queue<ptr_node<T>> queue;

    for (const auto& node : graph.nodes) {
        if (!nodes_with_parents.contains(node->data) && !visited.contains(node->data)) {
            queue.add(node);
            visited.insert(node->data);

            while (!queue.is_empty()) {
                auto x{queue.remove()};
                result.push_back(x->data);

                for (const auto& adj : x->adjacents)
                    if (!visited.contains(adj->data)) {
                        visited.insert(adj->data);
                        queue.add(adj);
                    }
            }
        }
    }

    if (result.size() != graph.nodes.size())
        throw invalid_argument("There is no valid build order to build projects");
    return result;
}
