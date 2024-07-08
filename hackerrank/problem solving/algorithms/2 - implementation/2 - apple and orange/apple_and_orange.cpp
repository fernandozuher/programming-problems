// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

using namespace std;

struct apple_and_orange
{
    int starting_sam{}, ending_sam{};
    int apple_tree_location{}, orange_tree_location{};
    int n_apples{}, n_oranges{};
    vector<int> apples_distance_from_tree;
    vector<int> oranges_distance_from_tree;
};

apple_and_orange read_input();
    template<class T = int>
    vector<T> read(int n);
tuple<int, int> count_apples_and_oranges(const apple_and_orange& input);
    int count_fruits_on_house(const apple_and_orange& input, string_view fruit);
        tuple<int, vector<int>> filter_input(const apple_and_orange& input, string_view fruit);

int main()
{
    const auto [apples_on_house, oranges_on_house] {count_apples_and_oranges(read_input())};
    cout << apples_on_house << '\n' << oranges_on_house;
    return 0;
}

    apple_and_orange read_input()
    {
        apple_and_orange input;
        cin >> input.starting_sam >> input.ending_sam;
        cin >> input.apple_tree_location >> input.orange_tree_location;
        cin >> input.n_apples >> input.n_oranges;
        input.apples_distance_from_tree = read(input.n_apples);
        input.oranges_distance_from_tree = read(input.n_oranges);
        return input;
    }

        template<class T>
        vector<T> read(const int n)
        {
            vector<T> array(n);
            copy_n(istream_iterator<T>(cin), n, array.begin());
            return array;
        }

    tuple<int, int> count_apples_and_oranges(const apple_and_orange& input)
    {
        int apples_on_house{count_fruits_on_house(input, "apple")};
        int oranges_on_house{count_fruits_on_house(input, "orange")};
        return {apples_on_house, oranges_on_house};
    }

        int count_fruits_on_house(const apple_and_orange& input, const string_view fruit)
        {
            const auto [tree_location, fruits]{filter_input(input, fruit)};

            auto is_fruit_located_inside_sam_range = [&](const int partial_location){
                int location{tree_location + partial_location};
                return location >= input.starting_sam && location <= input.ending_sam;
            };

            return static_cast<int>(ranges::count_if(fruits, is_fruit_located_inside_sam_range));
        }

            tuple<int, vector<int>> filter_input(const apple_and_orange& input, const string_view fruit)
            {
                if (fruit == "apple")
                    return {input.apple_tree_location, input.apples_distance_from_tree};
                return {input.orange_tree_location, input.oranges_distance_from_tree};
            }
