// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true
// C++23

import std;
using namespace std;

int page_count(int n, int page);

int main()
{
    int n, page;
    cin >> n >> page;
    println("{}", page_count(n, page));
    return 0;
}

// T: O(1)
// S: O(1) extra space
int page_count(int n, int page)
{
    int from_front{ page / 2 };
    int from_back{ n / 2 - from_front };
    return min(from_front, from_back);
}
