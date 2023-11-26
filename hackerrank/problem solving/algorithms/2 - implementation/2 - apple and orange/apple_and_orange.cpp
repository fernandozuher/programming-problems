// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int starting_sam, ending_sam;
    int apple_tree_location, orange_tree_location;
    int n_apples, n_oranges;
    vector<int> apples_distance_from_tree;
    vector<int> oranges_distance_from_tree;
} apple_and_orange;

apple_and_orange read_input();
    vector<int> read_int_array(const int n);
void count_apples_and_oranges(const apple_and_orange& input);
    int count_fruits_on_house(const apple_and_orange& input, const string& fruit);
        vector<vector<int>> filter_input(const apple_and_orange& input, const string& fruit);

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
            ranges::generate(array, [] {int n; cin >> n; return n;});
            return array;
        }

    void count_apples_and_oranges(const apple_and_orange& input)
    {
        int apples_on_house {count_fruits_on_house(input, "apple")};
        int oranges_on_house {count_fruits_on_house(input, "orange")};
        cout << apples_on_house << '\n' << oranges_on_house;
    }

        int count_fruits_on_house(const apple_and_orange& input, const string& fruit)
        {
            vector<vector<int>> filtered_input {filter_input(input, fruit)};
            int tree_location {filtered_input.front().front()};
            vector<int> fruits {filtered_input.back()};

            auto verify_fruit_location = [&] (const int partial_location) {
                int location {tree_location + partial_location};
                return location >= input.starting_sam && location <= input.ending_sam;
            };

            return ranges::count_if(fruits, verify_fruit_location);
        }

            vector<vector<int>> filter_input(const apple_and_orange& input, const string& fruit)
            {
                constexpr int data {2};
                vector<vector<int>> filtered_input(data);

                if (fruit == "apple") {
                    filtered_input.front().push_back(input.apple_tree_location);
                    filtered_input.back() = input.apples_distance_from_tree;
                }
                else {
                    filtered_input.front().push_back(input.orange_tree_location);
                    filtered_input.back() = input.oranges_distance_from_tree;
                }

                return filtered_input;
            }
