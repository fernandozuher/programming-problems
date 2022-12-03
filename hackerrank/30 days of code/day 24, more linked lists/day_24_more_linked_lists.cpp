#include <iostream>
#include <forward_list>

using namespace std;

namespace My_Static_List_Functions
{
    void remove_duplicates(forward_list<int>& data_list) {
        for (auto it = data_list.begin(); next(it) != data_list.end(); )
            *it == *next(it) ? data_list.erase_after(it) : ++it;
    }

    void display(forward_list<int>& data_list) {
        for (auto& data : data_list)
            cout << data << " ";
    }
}

int main() {
    int n;
    cin >> n;

    forward_list<int> data_list;
    auto it = data_list.before_begin();

    for (int data; n-- && cin >> data; it = data_list.insert_after(it, data));
    My_Static_List_Functions::remove_duplicates(data_list);
    My_Static_List_Functions::display(data_list);
}
