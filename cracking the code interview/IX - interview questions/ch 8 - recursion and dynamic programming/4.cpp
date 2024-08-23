// From C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

vector<vector<vector<int>>> all_subsets_from(const vector<int>& elements);
void print_subsets_of_nth_size(const vector<vector<int>>& subsets_of_nth_size);

int main()
{
    constexpr int n{5};
    vector<int> elements(n);
    ranges::iota(elements, 0);

    cout << "All subsets of set: ";
    ranges::copy(elements, ostream_iterator<int>(cout, " "));
    println("");

    for (const auto& [nth_size, subsets_of_nth_size] : views::zip(views::iota(1), all_subsets_from(elements))) {
        println("n = {}", nth_size);
        print_subsets_of_nth_size(subsets_of_nth_size);
        println("");
    }

    return 0;
}

vector<vector<vector<int>>> all_subsets_from(const vector<int>& elements)
{
    vector<vector<vector<int>>> subsets;

    // n + 1 to get subset with nth elements
    for (const int n{static_cast<int>(elements.size())}; const auto i : views::iota(1, n + 1)) {
        vector mask(i, true);
        mask.resize(n);
        const auto array_and_mask{
            [&mask, index = 0]([[maybe_unused]] int) mutable {
                return mask.at(index++);
            }
        };
        subsets.emplace_back();

        do {
            vector<int> current_subset(i);
            ranges::copy_if(elements, current_subset.begin(), array_and_mask);
            subsets.back().push_back(current_subset);
        }
        while (ranges::prev_permutation(mask).found);
    }

    return subsets;
}

void print_subsets_of_nth_size(const vector<vector<int>>& subsets_of_nth_size)
{
    for (const auto& subset_i : subsets_of_nth_size) {
        for (const auto element : subset_i)
            print("{} ", element);
        println("");
    }
}
