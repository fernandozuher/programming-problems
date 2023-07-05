// Source: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

class Binary_Gap
{
public:
    explicit Binary_Gap(const int number)
        : number{number}, binary{}, longest_binary_gap{0}
    {
        binary = {convert_int_to_binary_string(number)};
        find_longest_binary_gap();
    }

    int get_longest_binary_gap() const
    {
        return longest_binary_gap;
    }

private:
    int number;
    string binary;
    int longest_binary_gap;

    string convert_int_to_binary_string(const int number)
    {
        return bitset<sizeof(int) * 8>(number).to_string();
    }

    void find_longest_binary_gap()
    {
        for (vector<int> index {0, 0, 0}; ranges::find(index, -1) == index.end();) {
            const int gap_length {find_gap_length(index)};
            longest_binary_gap = {max(gap_length, longest_binary_gap)};
        }
    }

        int find_gap_length(vector<int>& index) const
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
};

int solution(const int number)
{
    const Binary_Gap obj(number);
    return obj.get_longest_binary_gap();
}
