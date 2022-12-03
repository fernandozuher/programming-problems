#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    forward_list<int> singly_list;

    for (auto end = singly_list.before_begin(); cin >> n; end = singly_list.insert_after(end, n));

    for (auto& node : singly_list)
        cout << node << ' ';

    return 0;
}
