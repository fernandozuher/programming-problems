// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

string convert_int_to_binary_string(const int number);
int find_longest_binary_gap(const string& binary);
    size_t find_gap_length(const string& binary, vector<size_t>& index);

int solution(const int number)
{
    const string binary {convert_int_to_binary_string(number)};
    return find_longest_binary_gap(binary);
}

    string convert_int_to_binary_string(const int number)
    {
        return bitset<sizeof(int) * 8>(number).to_string();
    }

    int find_longest_binary_gap(const string& binary)
    {
        size_t longest_binary_gap {0};

        for (vector<size_t> index {0, 0, 0}; ranges::find(index, -1) == index.end();) {
            const size_t gap_length {find_gap_length(binary, index)};
            longest_binary_gap = {max(gap_length, longest_binary_gap)};
        }

        return longest_binary_gap;
    }

        size_t find_gap_length(const string& binary, vector<size_t>& index)
        {
            const auto not_found = string::npos;
            index.front() = {binary.find('1', index.at(1))};

            if (index.front() != not_found) {
                index.at(1) = {binary.find('0', index.front() + 1)};

                if (index.at(1) != not_found) {
                    index.back() = {binary.find('1', index.at(1) + 1)};

                    if (index.back() != not_found) {
                        const size_t gap_length {index.back() - index.at(1)};
                        return gap_length;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
