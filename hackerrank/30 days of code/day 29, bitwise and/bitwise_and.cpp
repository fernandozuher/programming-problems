// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

#include <iostream>

using namespace std;

int bitwise_and(const int n, const int k);

int main()
{
    int n;
    cin >> n;

    for (int count, lim; n-- && cin >> count >> lim;)
        cout << bitwise_and(count, lim) << '\n';

    return 0;
}

    int bitwise_and(const int n, const int k)
    {
        int maximum_value_less_than_k {};

        for (int i {1}; i <= n; ++i)
            for (int j {i + 1}; j <= n; ++j) {
                int operation {i & j};

                if (operation < k && operation > maximum_value_less_than_k) {
                    if (operation == k - 1)
                        return operation;
                    else
                        maximum_value_less_than_k = operation;
                }
            }

        return maximum_value_less_than_k;
    }
