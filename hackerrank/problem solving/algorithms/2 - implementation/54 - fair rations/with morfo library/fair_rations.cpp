// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;
using namespace ranges;

int min_loaves_to_satisfy_rules(const vector<int>& people_loaf_counts);
bool is_odd(int n);

int main()
{
    morfo::skip_input_ln();
    vector<int> people_loaf_counts = morfo::readln<vector<int>>();
    int min_loaves{ min_loaves_to_satisfy_rules(people_loaf_counts) };
    if (min_loaves == -1)
        cout << "NO";
    else
        cout << min_loaves;
    return 0;
}

// n: length of people_loaf_counts
// T: O(n)
// S: O(1) extra space
int min_loaves_to_satisfy_rules(const vector<int>& people_loaf_counts)
{
    int loaves_given{};
    int counts{ people_loaf_counts.front() };

    for (auto x : people_loaf_counts | views::drop(1))
        if (is_odd(counts)) {
            loaves_given += 2;
            counts = x + 1;
        }
        else
            counts = x;

    return is_odd(counts) ? -1 : loaves_given;
}

bool is_odd(int n)
{
    return n & 1;
}
