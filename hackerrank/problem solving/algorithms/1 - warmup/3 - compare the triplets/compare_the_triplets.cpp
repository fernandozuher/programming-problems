// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int size);
pair<int, int> compare_triplets(const vector<int>& array1, const vector<int>& array2);

int main()
{
    const int size {3};
    vector<int> array1 {read_int_array(size)};
    vector<int> array2 {read_int_array(size)};
    pair<int, int> result {compare_triplets(array1, array2)};
    cout << result.first << ' ' << result.second;

    return 0;
}

    vector<int> read_int_array(const int size)
    {
        vector<int> array(size);
        generate(array.begin(), array.end(), [] {int n; cin >> n; return n;});
        return array;
    }

    pair<int, int> compare_triplets(const vector<int>& array1, const vector<int>& array2)
    {
        int player1 {}, player2 {};

        for (int n = array1.size(); n--;)
            if (array1.at(n) > array2.at(n))
                player1++;
            else if (array2.at(n) > array1.at(n))
                player2++;

        return pair{player1, player2};
    }
