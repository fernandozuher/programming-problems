// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <numeric>
#include <valarray>

using namespace std;

int max_hourglass_sum(const valarray<int>& matrix);
int hourglass_sum(const valarray<int>& matrix, const int index);

constexpr int stride {6};

int main()
{
    constexpr int n {6};
    valarray<int> matrix(n * n);
    ranges::generate(matrix, [] {int x; cin >> x; return x;});
    cout << max_hourglass_sum(matrix);

    return 0;
}

    int max_hourglass_sum(const valarray<int>& matrix)
    {
        int max_sum {numeric_limits<int>::min()};
        constexpr int middle_hourglass_first_index {7};
        constexpr int n_sub_rows_cols {4};
        constexpr int n {stride * n_sub_rows_cols + 1};

        for (int i {middle_hourglass_first_index}; i <= n; i += stride)
            for (int j {i}, cols {4}, n2 {j + cols}; j < n2; ++j) {
                int current_sum {hourglass_sum(matrix, j)};
                max_sum = max(max_sum, current_sum);
            }

        return max_sum;
    }

        int hourglass_sum(const valarray<int>& matrix, const int index)
        {
            int subrow_1_first_index {index - stride - 1};
            int subrow_3_first_index {index + stride - 1};
            constexpr int n {3};
            constexpr int stride {1};

            auto subrow_1 {slice(subrow_1_first_index, n, stride)};
            auto subrow_3 {slice(subrow_3_first_index, n, stride)};

            return matrix[subrow_1].sum() + matrix[index] + matrix[subrow_3].sum();
        }
