// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

#include <iostream>

using namespace std;

int page_count(int n, int page);

int main()
{
    int n, page;
    cin >> n >> page;
    cout << page_count(n, page) << '\n';
    return 0;
}

int page_count(int n, int page)
{
    int from_front{page / 2};
    int from_back{n / 2 - from_front};
    return min(from_front, from_back);
}
