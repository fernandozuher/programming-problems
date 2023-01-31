// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <bitset> // bitset
#include <string> // string
#include <algorithm> // max

using namespace std;

string convert_int_to_binary_string(const int N);
int find_longest_binary_gap(const string BINARY);
    int find_gap_length(const string BINARY, vector<int> &index);


int solution(const int N) {
    const string BINARY {convert_int_to_binary_string(N)};
    const int LONGEST_BINARY_GAP {find_longest_binary_gap(BINARY)};
    return LONGEST_BINARY_GAP;
}

    string convert_int_to_binary_string(const int N) {
        const string BINARY {bitset<sizeof(int) * 8>(N).to_string()};
        return BINARY;
    }

    int find_longest_binary_gap(const string BINARY) {
        int longest_binary_gap {0};

        for (vector<int> index {0, 0, 0}; ranges::find(index, -1) == index.end();) {
            const int GAP_LENGTH {find_gap_length(BINARY, index)};
            longest_binary_gap = {max(GAP_LENGTH, longest_binary_gap)};
        }

        return longest_binary_gap;
    }

        int find_gap_length(const string BINARY, vector<int> &index) {
            const auto not_found = static_cast<int>(string::npos);

            index.front() = {static_cast<int>(BINARY.find('1', index.at(1)))};
            if (index.front() != not_found) {

                index.at(1) = {static_cast<int>(BINARY.find('0', index.front() + 1))};
                if (index.at(1) != not_found) {

                    index.back() = {static_cast<int>(BINARY.find('1', index.at(1) + 1))};
                    if (index.back() != not_found) {

                        const int GAP_LENGTH {index.back() - index.at(1)};
                        return GAP_LENGTH;
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
