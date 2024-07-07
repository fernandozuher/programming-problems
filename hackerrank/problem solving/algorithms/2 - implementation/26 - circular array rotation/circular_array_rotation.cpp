// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T = int>
vector<T> read(int n);
int reduce_rotations(int n, int rotation_count);
void print_array_according_to_index_from_another_array(const vector<int>& array1, const vector<int>& array2);

int main()
{
    int n, rotation_count, n_queries;
    cin >> n >> rotation_count >> n_queries;
    vector array{read(n)};
    vector queries{read(n_queries)};

    rotation_count = reduce_rotations(array.size(), rotation_count);
    ranges::rotate(array, array.end() - rotation_count);
    print_array_according_to_index_from_another_array(array, queries);

    return 0;
}

    template<class T>
    vector<T> read(const int n)
    {
        vector<T> array(n);
        copy_n(istream_iterator<T>(cin), n, array.begin());
        return array;
    }

    int reduce_rotations(const int n, const int rotation_count)
    {
        if (n > 1)
            return rotation_count >= n ? rotation_count % n : rotation_count;
        return 0;
    }

    void print_array_according_to_index_from_another_array(const vector<int>& array1, const vector<int>& array2)
    {
        for (const int i : array2)
            cout << array1.at(i) << '\n';
    }
