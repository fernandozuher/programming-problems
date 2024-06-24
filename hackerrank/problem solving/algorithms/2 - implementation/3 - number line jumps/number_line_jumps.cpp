// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
string kangaroo(const vector<int>& array);

int main()
{
    constexpr int n{4};
    vector array {read_int_array(n)};
    cout << kangaroo(array);
    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        copy_n(istream_iterator<int>(cin), n, array.begin());
        return array;
    }

    string kangaroo(const vector<int>& array)
    {
        int x1 {array.front()};
        int v1 {array.at(1)};
        int x2 {array.at(2)};
        int v2 {array.back()};

        if (v2 >= v1)
            return "NO";
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 == x2 ? "YES" : "NO";
    }
