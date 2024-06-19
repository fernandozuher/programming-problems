// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

typedef struct {
    int starting_sam{}, ending_sam{};
    int apple_tree_location{}, orange_tree_location{};
    int n_apples{}, n_oranges{};
    vector<int> apples_distance_from_tree;
    vector<int> oranges_distance_from_tree;
} apple_and_orange;

apple_and_orange read_input();
    vector<int> read_int_array(int n);
void count_apples_and_oranges(const apple_and_orange& input);
    int count_fruits_on_house(const apple_and_orange& input, string_view fruit);
        tuple<int, vector<int>> filter_input(const apple_and_orange& input, string_view fruit);

int main()
{
    apple_and_orange input {read_input()};
    count_apples_and_oranges(input);
    return 0;
}

    apple_and_orange read_input()
    {
        apple_and_orange input;
        cin >> input.starting_sam >> input.ending_sam;
        cin >> input.apple_tree_location >> input.orange_tree_location;
        cin >> input.n_apples >> input.n_oranges;
        input.apples_distance_from_tree = read_int_array(input.n_apples);
        input.oranges_distance_from_tree = read_int_array(input.n_oranges);
        return input;
    }

        vector<int> read_int_array(const int n)
        {
            vector<int> array(n);
            copy_n(istream_iterator<int>(cin), n, array.begin());
            return array;
        }

    void count_apples_and_oranges(const apple_and_orange& input)
    {
        int apples_on_house {count_fruits_on_house(input, "apple")};
        int oranges_on_house {count_fruits_on_house(input, "orange")};
        cout << apples_on_house << '\n' << oranges_on_house;
    }

        int count_fruits_on_house(const apple_and_orange& input, const string_view fruit)
        {
            const auto [tree_location, fruits] {filter_input(input, fruit)};

            auto verify_fruit_location = [&] (const int partial_location) {
                int location {tree_location + partial_location};
                return location >= input.starting_sam && location <= input.ending_sam;
            };

            return static_cast<int>(ranges::count_if(fruits, verify_fruit_location));
        }

            tuple<int, vector<int>> filter_input(const apple_and_orange& input, const string_view fruit)
            {
                if (fruit == "apple")
                    return {input.apple_tree_location, input.apples_distance_from_tree};
                return {input.orange_tree_location, input.oranges_distance_from_tree};
            }
