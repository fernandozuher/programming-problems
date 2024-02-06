// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Circular_Array_Rotation {
public:
    Circular_Array_Rotation(const vector<int>& array, const int rotation_count);
    vector<int> rotated_array() const;

private:
    vector<int> array;
    int rotation_count;

    void reduce_rotations();
    void rotate_array();
};

    Circular_Array_Rotation::Circular_Array_Rotation(const vector<int>& array, const int rotation_count)
        : array{array}, rotation_count{rotation_count}
    {
        reduce_rotations();
        rotate_array();
    }

        void Circular_Array_Rotation::reduce_rotations()
        {
            if (array.size() > 1)
                rotation_count = rotation_count >= array.size() ? rotation_count % array.size() : rotation_count;
            else
                rotation_count = 0;
        }

        void Circular_Array_Rotation::rotate_array()
        {
            auto first_part_array_begin_iterator = array.begin();
            auto first_part_array_end_iterator = array.begin() + array.size() - rotation_count;

            auto second_part_array_begin_iterator = array.begin() + array.size() - rotation_count;
            auto second_part_array_end_iterator = array.end();

            vector<int> new_array {second_part_array_begin_iterator, second_part_array_end_iterator};
            vector<int> second_part_new_array {first_part_array_begin_iterator, first_part_array_end_iterator};
            new_array.insert(new_array.end(), second_part_new_array.begin(), second_part_new_array.end());

            array = new_array;
        }

    vector<int> Circular_Array_Rotation::rotated_array() const
    {
        return array;
    }

//////////////////////////////////////////////////

template<class T = int>
vector<T> read(const int n);

void print_array_according_to_index_from_another_array(const vector<int>& array1, const vector<int>& array2);

int main()
{
    int n, rotation_count, n_queries;
    cin >> n >> rotation_count >> n_queries;
    vector<int> array {read(n)};
    vector<int> queries {read(n_queries)};

    Circular_Array_Rotation obj{array, rotation_count};
    print_array_according_to_index_from_another_array(obj.rotated_array(), queries);

    return 0;
}

    template<class T>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        auto read = []{T x; cin >> x; return x;};
        ranges::generate(array, read);
        return array;
    }

    void print_array_according_to_index_from_another_array(const vector<int>& array1, const vector<int>& array2)
    {
        auto print = [&](const auto & i) {cout << array1.at(i) << '\n';};
        ranges::for_each(array2, print);
    }
