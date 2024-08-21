// From C++23

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

struct Node {
    pair<int, int> index;
    shared_ptr<Node> right, down;
};

shared_ptr<Node> create_grid(int rows, int cols);
vector<vector<pair<int, int>>> generate_off_limit_cells(int n, int n_cols, int n_off_limit_cells);
vector<vector<int>> combination(const vector<int>& elements, int n);

bool find_path(const shared_ptr<Node>& node, vector<pair<int, int>>& path,
               const vector<pair<int, int>>& off_limit_cells);
void print_path_steps(const vector<pair<int, int>>& path);
void print_path_grid(vector<pair<int, int>> path, int rows, int cols, const vector<pair<int, int>>& off_limit_cells);

int main()
{
    constexpr int start_row{3}, end_row{4};
    constexpr int start_col{3}, end_col{4};
    constexpr int n_off_limit_cells{2};

    for (const auto rows : views::iota(start_row, end_row))
        for (const auto cols : views::iota(start_col, end_col)) {
            const auto root{create_grid(rows, cols)};

            vector<vector<pair<int, int>>> vec_off_cells;
            for (const auto i : views::iota(1, n_off_limit_cells + 1)) // 1 to avoid 0 off_time_cells
                ranges::copy(generate_off_limit_cells(rows * cols, cols, i), back_inserter(vec_off_cells));

            for (const auto& off_cells : vec_off_cells) {
                vector<pair<int, int>> path;
                if (find_path(root, path, off_cells))
                    print_path_steps(path);
                else
                    println("There is not path for the robot to travel from the top left to the bottom right");

                println("Grid {} x {}", rows, cols);
                print_path_grid(path, rows, cols, off_cells);
                println("");
            }
        }

    return 0;
}

vector<vector<pair<int, int>>> generate_off_limit_cells(const int n, const int n_cols, const int n_off_limit_cells)
{
    vector<int> elements(n - 2); // -2 because first and last position are not included
    ranges::iota(elements, 1); // From 1 to not include first element
    vector partial_combination{combination(elements, n_off_limit_cells)};

    const auto from_n_to_pair_index{
        [n_cols](const auto num) {
            const auto [i, j]{div(num, n_cols)};
            return pair{i, j};
        }
    };

    vector<vector<pair<int, int>>> off_time_cells;
    for (const auto& vec : partial_combination) {
        const auto vec_pair_index{vec | views::transform(from_n_to_pair_index) | ranges::to<vector>()};
        off_time_cells.push_back(vec_pair_index);
    }

    return off_time_cells;
}

vector<vector<int>> combination(const vector<int>& elements, const int n)
{
    vector<vector<int>> permutation{{}};
    vector mask(n, true);
    mask.resize(elements.size());

    do {
        for (const auto [i, x] : mask | views::enumerate)
            if (x)
                permutation.back().push_back(elements.at(i));
        permutation.emplace_back();
    }
    while (ranges::prev_permutation(mask).found);

    permutation.pop_back();
    return permutation;
}

shared_ptr<Node> create_grid(const int rows, const int cols)
{
    map<pair<int, int>, shared_ptr<Node>> my_map;

    for (const auto i : views::iota(0, rows))
        for (const auto j : views::iota(0, cols))
            my_map[{i, j}] = make_shared<Node>(pair{i, j});

    for (const auto& [index, node] : my_map) {
        const auto [i, j]{index};
        if (i + 1 < rows)
            node->down = my_map[{i + 1, j}];
        if (j + 1 < cols)
            node->right = my_map[{i, j + 1}];
    }

    return my_map[{0, 0}];
}

bool find_path(const shared_ptr<Node>& node, vector<pair<int, int>>& path,
               const vector<pair<int, int>>& off_limit_cells)
{
    path.push_back(node->index);

    if (const auto leaf{!node->right && !node->down}; leaf)
        return true;

    vector<shared_ptr<Node>> nodes;
    if (node->right)
        nodes.push_back(node->right);
    if (node->down)
        nodes.push_back(node->down);

    for (const auto& way : nodes) {
        // Linear search here because it is faster than binary search for small off_limit_cells
        if (ranges::find(off_limit_cells, way->index) != off_limit_cells.end())
            continue;

        if (find_path(way, path, off_limit_cells))
            return true;
    }

    path.pop_back();
    return false;
}

void print_path_steps(const vector<pair<int, int>>& path)
{
    cout << "Path: ";
    for (const auto& pairs : path | views::slide(2)) {
        const auto [current_i, current_j]{tuple{pairs.front().first, pairs.front().second}};
        const auto [next_i, next_j]{tuple{pairs.back().first, pairs.back().second}};

        if (current_i < next_i)
            print("{},{} v ", current_i, current_j);
        else
            print("{},{} > ", current_i, current_j);
    }

    if (!path.empty())
        print("{},{}", path.back().first, path.back().second);
    println("");
}

// There is a copy of "path" here because I don't want to change the original order after sorting it in this function
void print_path_grid(vector<pair<int, int>> path, const int rows, const int cols,
                     const vector<pair<int, int>>& off_limit_cells)
{
    cout << setw(3) << " ";
    for (const auto i : views::iota(0, cols))
        cout << setw(3) << i;
    println("");

    // For binary search below
    ranges::sort(path);

    for (const auto i : views::iota(0, rows)) {
        cout << setw(4) << i;
        for (const auto j : views::iota(0, cols))
            // Linear search here because it is faster than binary search for small off_limit_cells
            if (ranges::find(off_limit_cells, pair{i, j}) != off_limit_cells.end())
                cout << setw(3) << "X ";
                // Binary search here because it is faster than linear search for non-small paths
            else if (ranges::binary_search(path, pair{i, j}))
                cout << setw(3) << "- ";
            else
                cout << setw(3) << "  ";
        println("");
    }
}
