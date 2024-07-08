// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using namespace std;

constexpr int input_size{4};

template<class T = int>
array<T, input_size> read_input();
template<class T = int>
string kangaroo(const array<T, input_size>& array);

int main()
{
    cout << kangaroo(read_input());
    return 0;
}

    template<class T>
    array<T, input_size> read_input()
    {
        array<T, input_size> array;
        copy_n(istream_iterator<T>(cin), input_size, array.begin());
        return array;
    }

    template<class T>
    string kangaroo(const array<T, input_size>& array)
    {
        auto [x1, v1, x2, v2]{array};
        if (v2 >= v1)
            return "NO"s;
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 == x2 ? "YES"s : "NO"s;
    }
