// From C++23

#include <bitset>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

int flit_bit_to_win(const string_view& str);
vector<pair<int, int>> filter_adjacent_zeros_and_ones(const string_view& str);
int when_one_value(const vector<pair<int, int>>& zeros_and_ones);
int when_two_values(const vector<pair<int, int>>& zeros_and_ones);
int when_three_values(const vector<pair<int, int>>& zeros_and_ones);

int main()
{
    println("X (int), Y (in bits), Z (length of the longest sequence of 1s)");
    constexpr int n{2000};
    for (const auto i : views::iota(0, n)) {
        bitset<sizeof(int) * 8> bits(i);
        auto str{bits.to_string()};
        println("{}, {}, {}", i, str, flit_bit_to_win(str));
    }
    return 0;
}

int flit_bit_to_win(const string_view& str)
{
    const vector zeros_and_ones{filter_adjacent_zeros_and_ones(str)};
    if (zeros_and_ones.size() == 1)
        return when_one_value(zeros_and_ones);
    if (zeros_and_ones.size() == 2)
        return when_two_values(zeros_and_ones);
    return when_three_values(zeros_and_ones);
}

vector<pair<int, int>> filter_adjacent_zeros_and_ones(const string_view& str)
{
    vector<pair<int, int>> zeros_and_ones;

    int zeros{}, ones{};
    for (const auto ch : str) {
        if (ch == '0' && !ones)
            ++zeros;
        else if (ch == '0' && ones) {
            zeros_and_ones.emplace_back(1, ones);
            ones = 0;
            zeros = 1;
        }
        else if (ch == '1' && !zeros)
            ++ones;
        else if (ch == '1' && zeros) {
            zeros_and_ones.emplace_back(0, zeros);
            zeros = 0;
            ones = 1;
        }
    }

    if (zeros)
        zeros_and_ones.emplace_back(0, zeros);
    else
        zeros_and_ones.emplace_back(1, ones);

    return zeros_and_ones;
}

int when_one_value(const vector<pair<int, int>>& zeros_and_ones)
{
    // 1...
    if (zeros_and_ones.front().first == 1)
        return zeros_and_ones.front().second;
    // 0...
    return 1;
}

int when_two_values(const vector<pair<int, int>>& zeros_and_ones)
{
    // 1... 0...
    if (zeros_and_ones.front().first == 1)
        return zeros_and_ones.front().second + 1;
    // 0... 1...
    return zeros_and_ones.back().second + 1;
}

int when_three_values(const vector<pair<int, int>>& zeros_and_ones)
{
    int longest_ones{};

    for (const auto& data : zeros_and_ones | views::slide(3)) {
        // 1... 0 ...1
        if (data.front().first == 1 && data.at(1).second == 1)
            longest_ones = max(longest_ones, data.front().second + 1 + data.at(2).second);
            // 1... ...0... ...1
        else if (data.front().first == 1 && data.at(1).second > 1) {
            longest_ones = max(longest_ones, data.front().second + 1);
            longest_ones = max(longest_ones, data.back().second + 1);
        }
        // 0... ...1... ...0
        else
            longest_ones = max(longest_ones, data.at(1).second + 1);
    }

    return longest_ones;
}
