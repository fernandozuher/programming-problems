// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <bitset>
#include <iostream>
#include <tuple>

using namespace std;

int max_consecutive_ones_from(const bitset<32>& binary);
tuple<int, int> count_ones_in_sequence(int i, const bitset<32>& binary);
int find_last_index_with_consecutive_ones(int i, const bitset<32>& binary);

int main()
{
    int n;
    cin >> n;
    auto binary{bitset<32>(n)};
    cout << max_consecutive_ones_from(binary);
    return 0;
}

int max_consecutive_ones_from(const bitset<32>& binary)
{
    int max_consecutive_ones{};
    for (int i{}, consecutive_ones{}; i < binary.size(); ++i)
        if (const bool is_bit_on{binary[i]}; is_bit_on) {
            tie(i, consecutive_ones) = count_ones_in_sequence(i, binary);
            max_consecutive_ones = max(consecutive_ones, max_consecutive_ones);
        }
    return max_consecutive_ones;
}

tuple<int, int> count_ones_in_sequence(int i, const bitset<32>& binary)
{
    int first_index{i};
    int last_index{find_last_index_with_consecutive_ones(i, binary)};
    int consecutive_ones{last_index - first_index + 1};
    return {last_index, consecutive_ones};
}

int find_last_index_with_consecutive_ones(int i, const bitset<32>& binary)
{
    ++i;
    for (; i < binary.size() && binary[i]; ++i);
    return i - 1;
}
