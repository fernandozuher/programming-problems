// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int save_the_prisoner(const int prisoners, const int sweets, const int chair_number_to_begin);
template<class T = int>
void print_array(const vector<T>& array);

int main()
{
    int n;
    cin >> n;
    vector<int> prisoners_chair_number_to_warn(n);

    for (int& x : prisoners_chair_number_to_warn) {
        int prisoners, sweets, chair_number_to_begin;
        cin >> prisoners >> sweets >> chair_number_to_begin;
        x = save_the_prisoner(prisoners, sweets, chair_number_to_begin);
    }

    print_array(prisoners_chair_number_to_warn);

    return 0;
}

    int save_the_prisoner(const int prisoners, const int sweets, const int chair_number_to_begin)
    {
        int prisoner_chair_number_to_warn {chair_number_to_begin + (sweets - 1)};
        int x {prisoner_chair_number_to_warn};

        if (x > prisoners) {
            x %= prisoners;
            if (x == 0)
                x = prisoners;
        }

        return x;
    }

    template<class T>
    void print_array(const vector<T>& array)
    {
        auto print {[](auto element) {cout << element << '\n';}};
        ranges::for_each(array, print);
    }
