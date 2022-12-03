#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

int bubble_sort(vector<int> *a)
{
    int number_of_swaps {};
    for (auto& _ : *a) {
        for (int j {}, N = a->size() - 1; j < N; ++j)
            if (a->at(j) > a->at(j + 1))
                swap(a->at(j), a->at(j + 1)), number_of_swaps++;

        if (!number_of_swaps)
            break;
    }
    return number_of_swaps;
}

int main()
{
    string s;
    getline(cin, s);
    getline(cin, s);

    vector<int> v;
    int n;
    for (stringstream iss(s); iss >> n; v.push_back(n));

    cout << "Array is sorted in " << bubble_sort(&v) << " swaps.";
    cout << "\nFirst Element: " << v.front();
    cout << "\nLast Element: " << v.back();

    return 0;
}
