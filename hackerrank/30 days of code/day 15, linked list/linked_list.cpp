// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

#include <forward_list>
#include <iostream>
#include <iterator>
#include <ranges>

using namespace std;

forward_list<int> initialize_list(int n);
void display_list(const forward_list<int>& list);

int main()
{
    int size;
    cin >> size;
    forward_list<int> list{initialize_list(size)};
    display_list(list);
    return 0;
}

forward_list<int> initialize_list(int n)
{
    return views::iota(0, n) | views::transform([](auto) {int x; cin >> x; return x;}) | ranges::to<forward_list<int>>();
}

void display_list(const forward_list<int>& list)
{
    ranges::copy(list, ostream_iterator<int>(cout, " "));
}
