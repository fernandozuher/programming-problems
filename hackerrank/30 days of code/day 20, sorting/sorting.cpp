// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int bubble_sort(vector<int>& v);

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    string s;
    getline(cin, s); // remove new line character
    getline(cin, s);
    stringstream is(s);
    ranges::generate(v, [&is]{int x; is >> x; return x;});

    cout << "Array is sorted in " << bubble_sort(v) << " swaps.";
    cout << "\nFirst Element: " << v.front();
    cout << "\nLast Element: " << v.back();

    return 0;
}

    int bubble_sort(vector<int>& v)
    {
        int number_of_swaps {};

        for (int n = v.size(); --n;) {
            for (int i {}; i < n; ++i)
                if (v.at(i) > v.at(i + 1)) {
                    swap(v.at(i), v.at(i + 1));
                    ++number_of_swaps;
                }

            if (!number_of_swaps)
                break;
        }

        return number_of_swaps;
    }
