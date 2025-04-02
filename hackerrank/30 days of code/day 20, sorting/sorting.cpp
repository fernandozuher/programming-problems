// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true
// C++23

#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

vector<int> read_input();
int bubble_sort(vector<int>& v);
tuple<int, int> sort_slice(auto v);

int main()
{
    vector numbers{read_input()};
    int n_swaps{bubble_sort(numbers)};
    cout << "Array is sorted in " << n_swaps << " swaps.";
    cout << "\nFirst Element: " << numbers.front();
    cout << "\nLast Element: " << numbers.back();
    return 0;
}

vector<int> read_input()
{
    int n;
    cin >> n;
    return views::iota(0, n) | views::transform([](auto) { int x; cin >> x; return x; }) | ranges::to<vector<int>>();
}

int bubble_sort(vector<int>& v)
{
    int total_swaps{};
    for (auto end = v.size(); end;) {
        auto [n_swaps, new_end] = sort_slice(v | views::take(end));
        total_swaps += n_swaps;
        end = new_end;
    }
    return total_swaps;
}

tuple<int, int> sort_slice(auto v)
{
    int n_swaps{}, new_end{};
    for (auto [i, elements] : v | views::slide(2) | views::enumerate) {
        if (elements[0] > elements[1]) {
            swap(elements[0], elements[1]);
            ++n_swaps;
            new_end = i + 1;
        }
    }
    return {n_swaps, new_end};
}
