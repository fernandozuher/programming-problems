// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true
// From C++20 onward

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Difference {
    vector<int> elements;

public:
    int maximum_difference{};

    explicit Difference(const vector<int>& elements): elements{elements} {}

    void compute_difference()
    {
        const auto [min, max]{ranges::minmax_element(elements)};
        maximum_difference = *max - *min;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    copy_n(istream_iterator<int>(cin), n, numbers.begin());

    Difference difference{numbers};
    difference.compute_difference();
    cout << difference.maximum_difference;

    return 0;
}
