// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

string convert_int_to_binary_string(const int number);
int find_longest_binary_gap(const string& binary);
    int find_gap_length(const string& binary, vector<int>& index);

int solution(const int number)
{
    const string binary {convert_int_to_binary_string(number)};
    const int longest_binary_gap {find_longest_binary_gap(binary)};
    return longest_binary_gap;
}

    string convert_int_to_binary_string(const int number)
    {
        return bitset<sizeof(int) * 8>(number).to_string();
    }

    int find_longest_binary_gap(const string& binary)
    {
        int longest_binary_gap {0};

        for (vector<int> index {0, 0, 0}; ranges::find(index, -1) == index.end();) {
            const int gap_length {find_gap_length(binary, index)};
            longest_binary_gap = {max(gap_length, longest_binary_gap)};
        }

        return longest_binary_gap;
    }

        int find_gap_length(const string& binary, vector<int>& index)
        {
            const auto not_found = static_cast<int>(string::npos);
            index.front() = {static_cast<int>(binary.find('1', index.at(1)))};

            if (index.front() != not_found) {
                index.at(1) = {static_cast<int>(binary.find('0', index.front() + 1))};

                if (index.at(1) != not_found) {
                    index.back() = {static_cast<int>(binary.find('1', index.at(1) + 1))};

                    if (index.back() != not_found) {
                        const int gap_length {index.back() - index.at(1)};
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
