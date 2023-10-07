// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

#include <iostream>
#include <forward_list>

using namespace std;

namespace My_Static_List_Functions
{
    template<typename T>
    void remove_duplicates(forward_list<T>& data_list)
    {
        for (auto it = data_list.begin(); next(it) != data_list.end();)
            *it == *next(it) ? data_list.erase_after(it) : ++it;
    }

    template<typename T>
    void display(const forward_list<T>& data_list)
    {
        for (const auto& data : data_list)
            cout << data << " ";
    }
}

using namespace My_Static_List_Functions;

int main()
{
    int n;
    cin >> n;

    forward_list<int> data_list;
    auto it = data_list.before_begin();

    for (int data; n-- && cin >> data; it = data_list.insert_after(it, data));
    remove_duplicates(data_list);
    display(data_list);
}
