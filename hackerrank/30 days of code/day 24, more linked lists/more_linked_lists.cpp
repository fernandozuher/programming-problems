// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true
// C++23

#include <iostream>
#include <forward_list>
#include <ranges>

using namespace std;

template<class T = int>
forward_list<T> read_list();

template<class T = int>
void remove_duplicates(forward_list<T>& l);

template<class T = int>
void display(const forward_list<T>& l);

int main()
{
    forward_list data_list{read_list()};
    remove_duplicates(data_list);
    display(data_list);
}

template<class T>
forward_list<T> read_list()
{
    int n;
    cin >> n;
    return views::iota(0, n) | views::transform([](auto) { T x; cin >> x; return x; }) | ranges::to<forward_list>();
}

template<class T>
void remove_duplicates(forward_list<T>& l)
{
    l.unique();
}

template<class T>
void display(const forward_list<T>& l)
{
    ranges::copy(l, ostream_iterator<T>(cout, " "));
}
