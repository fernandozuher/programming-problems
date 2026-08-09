// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

void print_queries(const vector<int>& arr, int n_rotation, int n_queries);

int main()
{
    int n = morfo::read();
    int n_rotation = morfo::read();
    int n_queries = morfo::read();
    vector<int> arr = morfo::read(n);
    print_queries(arr, n_rotation, n_queries);
    return 0;
}

// T: O(n_queries)
// S: O(1) extra space
void print_queries(const vector<int>& arr, int n_rotation, int n_queries)
{
    int n = arr.size();
    int offset{ n - n_rotation % n };
    for (int i{}; i < n_queries; ++i) {
        int query = morfo::read();
        int idx{ (query + offset) % n };
        println("{}", arr.at(idx));
    }
}
