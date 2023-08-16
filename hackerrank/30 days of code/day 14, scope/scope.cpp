// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximum_difference;

    Difference(const vector<int>& elements): elements{elements} {}

    void compute_difference()
    {
        ranges::sort(elements);
        maximum_difference = {elements.back() - elements.front()};
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    ranges::generate(array, [] {int n; cin >> n; return n;});

    Difference difference {array};
    difference.compute_difference();
    cout << difference.maximum_difference;

    return 0;
}
