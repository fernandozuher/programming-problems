// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-divisibleSumPairs-bar/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(const int n);

class Subarray_Division {
public:
    Subarray_Division(const vector<int>& array, const int k):
        array{array}, k{k}, n_divisible{}
    {
        divisible_sum_pairs();
    }

    int n_divisible_sum_pairs() const
    {
        return n_divisible;
    }

private:
    vector<int> array;
    int k;
    int n_divisible;

    void divisible_sum_pairs()
    {
        int n = array.size();
        for (int i {}, n2 {n - 1}; i < n2; ++i)
            for (int j {i + 1}; j < n; ++j)
                if (array[i] <= array[j] && !((array[i] + array[j]) % k))
                    ++n_divisible;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> array {read_int_array(n)};

    sort(array);

    Subarray_Division obj{array, k};
    cout << obj.n_divisible_sum_pairs();

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        generate(array.begin(), array.end(), [] {int n; cin >> n; return n;});
        return array;
    }
