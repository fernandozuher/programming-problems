// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C++23

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<long> read_int_array(int n);
pair<long, long> min_max_sum(const vector<long>& array);

int main()
{
    constexpr int n{5};
    vector array {read_int_array(n)};
    auto [min, max] {min_max_sum(array)};
    cout << min << ' ' << max;

    return 0;
}

    vector<long> read_int_array(const int n)
    {
        vector<long> array(n);
        copy_n(istream_iterator<long>(cin), n, array.begin());
        return array;
    }

    pair<long, long> min_max_sum(const vector<long>& array)
    {
        long sum {*ranges::fold_left_first(array, plus())};
        const auto [min, max] {ranges::minmax_element(array)};
        long min_sum {sum - *max};
        long max_sum {sum - *min};
        return {min_sum, max_sum};
    }
