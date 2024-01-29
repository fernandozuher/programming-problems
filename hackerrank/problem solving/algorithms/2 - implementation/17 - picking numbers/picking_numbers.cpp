// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<class T = int>
vector<T> read_array(const int n);

class Picking_Numbers {

public:
    Picking_Numbers(const vector<int>& array);
    int subarray_biggest_size() const;

private:
    vector<int> numbers;
    int subarray_biggest_length;

    void picking_numbers();
    int update_subarray_biggest_length(const int subarray_current_size) const;
    vector<int> update_first_reference_number_index_and_subarray_current_size(const int i, const int second_reference_number_index) const;
};

    Picking_Numbers::Picking_Numbers(const vector<int>& array): numbers{array}, subarray_biggest_length{1}
    {
        picking_numbers();
    }

    int Picking_Numbers::subarray_biggest_size() const
    {
        return subarray_biggest_length;
    }

    void Picking_Numbers::picking_numbers()
    {
        int first_reference_number_index{};
        int second_reference_number_index{};
        int subarray_current_size{1};

        for (int i{1}, n = numbers.size(); i < n; ++i) {
            int difference {numbers.at(i) - numbers.at(first_reference_number_index)};

            switch (difference) {
            case 0:
                ++subarray_current_size;
                break;

            case 1:
                ++subarray_current_size;
                if (numbers.at(second_reference_number_index) != numbers.at(i))
                    second_reference_number_index = i;
                break;

            default:
                subarray_biggest_length = update_subarray_biggest_length(subarray_current_size);

                vector<int> update = update_first_reference_number_index_and_subarray_current_size(i, second_reference_number_index);

                first_reference_number_index = update.front();
                second_reference_number_index = i;
                subarray_current_size = update.back();
            }
        }

        subarray_biggest_length = update_subarray_biggest_length(subarray_current_size);
    }

        int Picking_Numbers::update_subarray_biggest_length(const int subarray_current_size) const
        {
            return max(subarray_current_size, subarray_biggest_length);
        }

        vector<int> Picking_Numbers::update_first_reference_number_index_and_subarray_current_size(const int i, const int second_reference_number_index) const
        {
            int first_reference_number_index, subarray_current_size;

            if (numbers.at(i) - numbers.at(second_reference_number_index) == 1) {
                first_reference_number_index = second_reference_number_index;
                subarray_current_size = i - second_reference_number_index + 1;
            }
            else {
                first_reference_number_index = i;
                subarray_current_size = 1;
            }

            return {first_reference_number_index, subarray_current_size};
        }

/////////////////////////////////////////////////

int main() {
    int n;
    cin >> n;

    vector<int> array {read_array(n)};
    ranges::sort(array);

    Picking_Numbers obj{array};
    cout << obj.subarray_biggest_size();

    return 0;
}

    template<class T = int>
    vector<T> read_array(const int n)
    {
        vector<T> array(n);
        ranges::generate(array, [] {T x; cin >> x; return x;});
        return array;
    }
