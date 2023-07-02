// Source: https://app.codility.com/programmers/lessons/1-iterations/binaryGap/

#include <bitset> // bitset
#include <string> // string
#include <algorithm> // max

using namespace std;


class Iterations {

private:
    string _binary;
    int _longest_binary_gap;

    string convert_int_to_binary_string(const int NUMBER) const {
        const string BINARY {bitset<sizeof(int) * 8>(NUMBER).to_string()};
        return BINARY;
    }

    int find_longest_binary_gap() const {
        int longest_binary_gap {0};

        for (vector<int> index {0, 0, 0}; ranges::find(index, -1) == index.end();) {
            const int GAP_LENGTH {find_gap_length(index)};
            longest_binary_gap = {max(GAP_LENGTH, longest_binary_gap)};
        }

        return longest_binary_gap;
    }

        int find_gap_length(vector<int> &index) const {
            const auto not_found = static_cast<int>(string::npos);
            index.front() = {static_cast<int>(_binary.find('1', index.at(1)))};

            if (index.front() != not_found) {
                index.at(1) = {static_cast<int>(_binary.find('0', index.front() + 1))};

                if (index.at(1) != not_found) {
                    index.back() = {static_cast<int>(_binary.find('1', index.at(1) + 1))};

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

public:
    Iterations(const int NUMBER) {
        _binary = convert_int_to_binary_string(NUMBER);
        _longest_binary_gap = find_longest_binary_gap();
    }

    int get_longest_binary_gap() const {
        return _longest_binary_gap;
    }

};

int solution(const int NUMBER) {
    const Iterations ITERATIONS(NUMBER);
    const int LONGEST_BINARY_GAP {ITERATIONS.get_longest_binary_gap()};
    return LONGEST_BINARY_GAP;
}