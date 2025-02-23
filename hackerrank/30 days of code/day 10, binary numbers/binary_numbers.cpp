// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#include <bitset>
#include <iostream>

using namespace std;

int count_max_consecutive_ones_in_binary_from(int n);
bitset<32> int_to_binary(int n);
int max_consecutive_ones_from(const bitset<32> &binary);

int main()
{
    int n;
    cin >> n;
    cout << count_max_consecutive_ones_in_binary_from(n);
    return 0;
}

int count_max_consecutive_ones_in_binary_from(const int n)
{
    bitset binary{int_to_binary(n)};
    return max_consecutive_ones_from(binary);
}

bitset<32> int_to_binary(const int n)
{
    return n;
}

int max_consecutive_ones_from(const bitset<32> &binary)
{
    int consecutive_ones{}, max_consecutive_ones{};
    for (int i{}; i < binary.size(); ++i)
        if (binary[i])
            ++consecutive_ones;
        else {
            max_consecutive_ones = max(consecutive_ones, max_consecutive_ones);
            consecutive_ones = 0;
        }
    return max(consecutive_ones, max_consecutive_ones);
}
